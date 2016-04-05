/*
 * Buffer.cpp
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#include "Buffer.h"

using namespace std;


Buffer::Buffer(int i, char* filename) {
	size = i/2;
	eof = false;
	posix_memalign((void**)&buffer1, 512, size*sizeof(char));
	posix_memalign((void**)&buffer2, 512, size*sizeof(char));
	// open() gibt FileDeskriptor zurück, wird für loadCharsFromFile() benötigt
	fd = open(filename, O_DIRECT);
	loadCharsFromFile(buffer1, size);
	next = &(buffer1[0]);
}

char Buffer::getchar(){
	// NULL kann sowohl "Ende Buffer" als auch EOF bedeuten
	if (*next == NULL) {
		// Ende Buffer1?
		// Buffer2 jetzt erst laden, damit es keine Probleme mit ungetchar() gibt
		if (next == &buffer1[size]) {
			loadCharsFromFile(buffer2, size);
			next = buffer2;
			//return *next++;
		}

		// Ende Buffer2?
		// s.o.
		else if (next == &buffer2[size]) {
			loadCharsFromFile(buffer1, size);
			next = buffer1;
			//return *next++;
		}

		else {
			// lexikalische Analyse beenden
			return 'EOF';
		}
	}
		return *next++;

}

// TODO Fall abfangen: Leere Datei eingelesen
bool Buffer::haschar(){
	if (eof) {
		return *next != NULL;
	}
	else {
		return true;
	}
}

// TODO muss evtl prüfen, ob nach Bufferwechsel mehr als _size_(hier 512) zeichen ungetted werden möchten.
void Buffer::ungetchar(){

	// Buffer muss zurück gewechselt werden, wenn next aktuell am ersten Zeichen steht
	if (next == &buffer1[0]) {
		next = &buffer2[size];
	}

	else if (next == &buffer2[0]) {
		next = &buffer2[size];
	}

	else {
		next--;
	}

}

void Buffer::loadCharsFromFile(char* buffer, int i) {

	int er = read(fd, buffer, i); // Letztes Zeichen im Buffer muss NULL sein

	if (er < 0) {
		cerr << "Error: " << strerror(errno);
	}

	// Datei schließen, wenn EOF
	if (er < i) {
		eof = true;
		int cl = close(fd);
	}
}



Buffer::~Buffer() {
	// TODO Auto-generated destructor stub
}
