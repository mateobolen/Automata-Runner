#include <memory>
#include <string>
#include <vector>
#ifndef STATE_H
#define STATE_H

struct transition;
using namespace std;

class State {
	private:
		string name;	//name of the state
		vector<transition> transitions;
		int base;
		bool isStart;
	public:
	State();

	State(string stateName, vector<transition> stateTransitions, bool isStateStart){
		name = stateName;
		transistions = stateTransitions;
		base = stateTransitions.size();
		isStart = isStateStart;
	}

	~State();

	//getters

	string getName() {
		return name;
	}

	vector<transition> getTransitions() {
		return transitions;
	}

	int getBase() {
		return base;
	}

	bool getIsStart() {
		return isStart;
	}


};


struct transition {
	unique_ptr<State> state;
	unique_ptr<State> nextState;
	char input;
};

#endif