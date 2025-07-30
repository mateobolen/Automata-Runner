#ifndef DFA_H
#define DFA_H

//#include <iostream>
#include "State.h"
#include <memory>
#include <vector>

struct transition;
using namespace std;


/* The class DFA makes an instance of a DFA which stands for Deterministic Finite Automaton.
 * A DFA is traditionally defined as a 5-tuple (Q,E,D,q,F) where:
 * Q is a finite set of states which will be represented by the vector of unique pointers named states.
 * E is a finite set of characters that represents the alphabet that the DFA uses which will be represented by the
 * vector of chars named alphabet.
 * D is the delta function which describes the transitions between states and will be represented by a vector of the
 * struct transition.
 * q is the start state which will be represented by a unique pointer that points to a state in states.
 * F is a finite set of states that are accept states and will be represented by a vector of unique pointers that point
 * to elements of states.
 *
*/
class DFA{
	private:
		vector<unique_ptr<State>> states;
		vector<char> alphabet;
		vector<transition> transitions;
		unique_ptr<State> startState;
		vector<unique_ptr<State>> acceptStates;
		int base;
		int size;
		bool accepts;
	public:
	DFA();

	DFA(vector<unique_ptr<State>> Q, vector<char> E, vector<transition> D, unique_ptr<State> q,
		vector<unique_ptr<State>> F) {
		states = Q;
		alphabet = E;
		transitions = D;
		startState = q;
		acceptStates = F;
		base = alphabet.size();
		size = states.size();
		bool accepts = false;
	}

	~DFA();

	//getters
	vector<unique_ptr<State>> getStates() {
		return states;
	}

	vector<char> getAlphabet() {
		return alphabet;
	}

	vector<unique_ptr<State>> getAcceptStates() {
		return acceptStates;
	}

	vector<transition> getTransitions() {
		return transitions;
	}

	unique_ptr<State> getStartState() {
		return startState;
	}

	vector<unique_ptr<State>> getAcceptsStates() {
		return acceptStates;
	}

	int getBase() {
		return base;
	}

	bool getAccepts() {
		return accepts;
	}
};

#endif