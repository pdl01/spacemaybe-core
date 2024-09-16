#include "game_state.h"
#include "currentsessiondata.h"

#include <iostream>

GameState::GameState(CurrentSessionData* currentSessionData,std::stack<State*>* _states)  :  State(currentSessionData,_states)
{

    std::cout << "Constructing GameState" << std::endl;

}



void GameState::update(const float& dt)
{

}

void GameState::render(sf::RenderTarget* target)
{
}