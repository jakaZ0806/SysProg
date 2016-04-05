/*
 * Token.cpp
 *
 *  Created on: 03.12.2014
 *      Author: thomas
 */

#include "Token.h"

Token::Token(TokenType token, int row, int column, int infoKey) {
	this->type = token;
	this->row = row;
	this->column = column;
	this->infoKey = infoKey;
}

Token::~Token() {
	// TODO Auto-generated destructor stub
}

