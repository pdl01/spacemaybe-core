#include "state.h"

#include <iostream>

State::State(CurrentSessionData* _currentSessionData,std::stack<State*>* _states) {
    this->currentSessionData = _currentSessionData;
    this->window = _currentSessionData->window;
    this->states = _states;
    std::cout << "Constructing State" << std::endl;
}

State::~State () {
    
}


