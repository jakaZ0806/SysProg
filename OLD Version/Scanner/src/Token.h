/*
 * Token.h
 *
 *  Created on: 03.12.2014
 *      Author: thomas
 */

#ifndef SCANNER_TOKEN_H_
#define SCANNER_TOKEN_H_

typedef enum {

	} TokenType;	// siehe Folie 11

class Token {

private:
	TokenType type;
	int row;
	int column;
	int infoKey;

public:
	Token(TokenType, int, int, int);
	virtual ~Token();
};

#endif /* SCANNER_TOKEN_H_ */
