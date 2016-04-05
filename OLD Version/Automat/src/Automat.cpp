/*
 * Automat.cpp
 *
 */

#include "Automat.h"


Automat::Automat() {
	currentState = start_state;
	lastFinalState = start_state;
	currentClosure = incomplete;
	stepsSinceFinalState = 0;
	signAccepted = false;
	row = 0;
	column = 0;
}

bool Automat::readChar(char c) {
	stateEval(currentState, c);

	return signAccepted;
}

void Automat::stateEval(state state, char c) {

	switch (state) {

		case start_state: {

			switch (c) {

				case '+': {
					currentState = signPlus_state;
					lastFinalState = signPlus_state;
					currentClosure = complete;
					signAccepted = true;
					break;
				}
				case '-': {
					currentState = signMinus_state;
					lastFinalState = signMinus_state;
					currentClosure = complete;
					signAccepted = true;
					break;
				}
				case '/': {
					currentState = signDiv_state;
					lastFinalState = signDiv_state;
					currentClosure = complete;
					signAccepted = true;
					break;
				}
				case '*': {
					currentState = signMultip_state;
					lastFinalState = signMultip_state;
					currentClosure = complete;
					signAccepted = true;
					break;
				}
				case '<': {
					currentState = signLess_state;
					lastFinalState = signLess_state;
					currentClosure = possibly_incomplete;
					signAccepted = true;
					break;
				}
				case '>': {
					currentState = signMore_state;
					lastFinalState = signMore_state;
					currentClosure = complete;
					signAccepted = true;
					break;
				}
				case '=': {
					currentState = signEqual_state;
					lastFinalState = signEqual_state;
					currentClosure = complete;
					signAccepted = true;
					break;
				}
				case ':': {
					currentState = colon_state;
					lastFinalState = colon_state;
					currentClosure = incomplete;
					stepsSinceFinalState++;
					signAccepted = true;
					break;
				}
				case '!': {
					currentState = signExcl_state;
					lastFinalState = signExcl_state;
					currentClosure = complete;
					signAccepted = true;
					break;
				}
				case '&': {
					currentState = signAnd_state;
					lastFinalState = signAnd_state;
					currentClosure = complete;
					signAccepted = true;
					break;
				}
				case ';': {
					currentState = signSemicolon_state;
					lastFinalState = signSemicolon_state;
					currentClosure = complete;
					signAccepted = true;
					break;
				}
				case '(': {
					currentState = signLPar_state;
					lastFinalState = signLPar_state;
					currentClosure = complete;
					signAccepted = true;
					break;
				}
				case ')': {
					currentState = signRPar_state;
					lastFinalState = signRPar_state;
					currentClosure = complete;
					signAccepted = true;
					break;
				}
				case '{': {
					currentState = signLBrace_state;
					lastFinalState = signLBrace_state;
					currentClosure = complete;
					signAccepted = true;
					break;
				}
				case '}': {
					currentState = signRBrace_state;
					lastFinalState = signRBrace_state;
					currentClosure = complete;
					signAccepted = true;
					break;
				}
				case '[': {
					currentState = signLBrack_state;
					lastFinalState = signLBrack_state;
					currentClosure = complete;
					signAccepted = true;
					break;
				}
				case ']': {
					currentState = signRBrack_state;
					lastFinalState = signRBrack_state;
					currentClosure = complete;
					signAccepted = true;
					break;
				}

				default: {
					// digit
					if (48 <= c && c <= 57) {
						currentState = integer_state;
						lastFinalState = integer_state;
						currentClosure = possibly_incomplete;
						signAccepted = true;
					}
					// letter
					else if ((65 <= c && c <= 90) || (97 <= c && c <= 122)) {
						currentState = identifier_state;
						lastFinalState = identifier_state;
						currentClosure = possibly_incomplete;
						signAccepted = true;
					}
					// Tab, Carriage Return, Leerzeichen
					else if (c == 9 || c == 13 || c == 32) {
						handleWhitespace(c);
					}
					else {
					// unerlaubtes Zeichen
						signAccepted = false;
					}
				}
			}

			break;
		}

		case integer_state: {
			if (48 <= c && c <= 57) {
				signAccepted = true;
			}
			// Tab, Carriage Return, Leerzeichen
			else if (c == 9 || c == 13 || c == 32) {
				handleWhitespace(c);
			}
			else signAccepted = false;
			break;
		}


		case identifier_state: {
			if ((65 <= c && c <= 90) || (97 <= c && c <= 122) || (48 <= c && c <= 57)) {
				signAccepted = true;
			}
			// Tab, Carriage Return, Leerzeichen
			else if (c == 9 || c == 13 || c == 32) {
				handleWhitespace(c);
			}
			else signAccepted = false;
			break;
		}

		case signLess_state: {
			if (c == ':') {
				currentState = lessColon_state;
				lastFinalState = signLess_state;
				currentClosure = possibly_incomplete;
				stepsSinceFinalState++;
				signAccepted = true;
			}
			// Tab, Carriage Return, Leerzeichen
			else if (c == 9 || c == 13 || c == 32) {
				handleWhitespace(c);
			}
			else signAccepted = false;
			break;
		}

		case lessColon_state: {
			if (c == '>') {
				currentState = signLessColonMore_state;
				lastFinalState = signLessColonMore_state;
				currentClosure = complete;
				stepsSinceFinalState = 0;
				signAccepted = true;
			}
			// Tab, Carriage Return, Leerzeichen
			else if (c == 9 || c == 13 || c == 32) {
				handleWhitespace(c);
			}
			else signAccepted = false;
			break;
		}

		case colon_state: {
			if (c == '=') {
				currentState = signIs_state;
				lastFinalState = signIs_state;
				currentClosure = complete;
				stepsSinceFinalState = 0;
				signAccepted = true;
			}
			// Tab, Carriage Return, Leerzeichen
			else if (c == 9 || c == 13 || c == 32) {
				handleWhitespace(c);
			}
			else signAccepted = false;
			break;
		}

		case signDiv_state: {
			if (c == '*') {
				currentState = commentStart_state;
				currentClosure = incomplete;
				stepsSinceFinalState++;
				signAccepted = true;
			}
			// Tab, Carriage Return, Leerzeichen
			else if (c == 9 || c == 13 || c == 32) {
				handleWhitespace(c);
			}
			else signAccepted = false;
			break;
		}

		case commentStart_state: {
			if (c == '*') {
				currentState = commentEnd_state;
				currentClosure = incomplete;
				stepsSinceFinalState++;
				signAccepted = true;
			}
			else if (/* erlaubte Zeichen*/ false) {

			}
			else signAccepted = false;
			break;
		}

		default: {
			signAccepted = false;
		}
	}
}

// TODO scanner melden, dass whitespace erkannt wurde
void Automat::handleWhitespace(char c) {
	// Carriage Return
	if (c == 13) {
		row++;
	}
	else {
		column++;
	}

	currentState = start_state;
	currentClosure = complete;
	stepsSinceFinalState++;
	signAccepted = false;
}

int Automat::getSteps() {
	return stepsSinceFinalState;
}

state Automat::getLastFinalState() {
	return lastFinalState;
}

closure Automat::getCurrentClosure() {
	return currentClosure;
}

int Automat::getRow() {
	return row;
}

int Automat::getColumn() {
	return column;
}

Automat::~Automat() {
	// TODO Auto-generated destructor stub
}
