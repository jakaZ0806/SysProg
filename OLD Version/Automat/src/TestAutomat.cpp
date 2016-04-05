#include "Automat.h"
#include "Buffer.h"
#include <iostream>
using namespace std;

int main (int argc, char* argv[]){

	Automat* automat = new Automat();

	automat->readChar('h');
	automat->readChar('a');
	automat->readChar('l');
	automat->readChar('l');
	automat->readChar('o');

	cout << automat->getLastFinalState() << endl;
	cout << automat->getCurrentClosure() << endl << endl;

	cout << automat->readChar(' ') << endl;

	cout << automat->getLastFinalState() << endl;
	cout << automat->getCurrentClosure() << endl << endl;

}
