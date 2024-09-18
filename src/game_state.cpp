#include "game_state.h"
#include "currentsessiondata.h"

#include <iostream>

GameState::GameState(CurrentSessionData* _currentSessionData,std::stack<State*>* _states) 
{

    std::cout << "Constructing GameState" << std::endl;
    this->states = _states;
    this->currentSessionData = _currentSessionData;
    this->window = _currentSessionData->window;
}



void GameState::update(const float& dt)
{

}

void GameState::render(sf::RenderTarget* target)
{
}