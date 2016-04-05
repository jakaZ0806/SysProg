/*
 * Automat.h
 *
 *  Created on: Jul 5, 2012
 *      Author: knad0001
 */

#ifndef Automat_H_
#define Automat_H_

#include <cstddef>

typedef enum {
	start_state,
	integer_state,
	identifier_state,
	signPlus_state,
	signMinus_state,
	signDiv_state,
	commentStart_state,
	commentEnd_state,
	signMultip_state,
	signLess_state,
	lessColon_state,
	signLessColonMore_state,
	signMore_state,
	signEqual_state,
	colon_state,
	signIs_state, // :=
	signExcl_state, // !
	signAnd_state, // &
	signSemicolon_state,
	signLPar_state, // (
	signRPar_state, // )
	signLBrace_state, // {
	signRBrace_state, // }
	signLBrack_state, // [
	signRBrack_state, // ]
	whitespace_state
} state;

typedef enum {
	complete,
	possibly_incomplete,
	incomplete
} closure; // Abgeschlossenheit

class Automat {

private:
	state currentState;
	state lastFinalState;
	closure currentClosure;
	bool signAccepted;
	int stepsSinceFinalState;
	int row;
	int column;

	void stateEval(state, char);
	void handleWhitespace(char);

public:
	Automat();
	bool readChar(char);
	int getSteps();
	virtual ~Automat();
	state getLastFinalState();
	closure getCurrentClosure();
	int getRow();
	int getColumn();
};

#endif /* Automat_H_ */
