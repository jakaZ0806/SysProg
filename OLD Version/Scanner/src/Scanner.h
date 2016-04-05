/*
 * Scanner.h
 *
 *  Created on: Sep 26, 2012
 *      Author: knad0001
 */

#ifndef SCANNER_H_
#define SCANNER_H_

#include <cstddef>
#include "Buffer.h"
#include "Automat.h"

using namespace std;

class Scanner {
public:
	Scanner(char*);
	virtual ~Scanner();
	Token nextToken();

private:
	Token currentToken;
	Buffer* buffer;
	Automat* automat;
	char* tokenBuffer;
	char* next;
	Token makeToken();
};

#endif /* SCANNER_H_ */
