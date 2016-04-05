/*
 * Scanner.cpp
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#include "Scanner.h"
#include "Buffer.h"
#include "Automat.h"

using namespace std;


Scanner::Scanner(char* filename) {
	currentToken = NULL;
	*buffer = new Buffer(1024, filename);
	*automat = new Automat();
	tokenBuffer = new char[1024];
	*next = tokenBuffer[0];
}

Token Scanner::nextToken() {
	while (buffer->haschar()) {
		char c = buffer->getchar();

		bool accepted = automat->readChar(c);

		if (accepted) {
			next = c;
			next++;
		}
		else {
			if (automat->getCurrentClosure() == complete) {
				Token token = makeToken();

				return token;
			}
		}
	}

}

Token Scanner::makeToken() {
	int column = 0;
	int row = automat->getRow();


	while (next != tokenBuffer) {
		column++;
	}
}

Scanner::~Scanner() {
	delete tokenBuffer;
}
