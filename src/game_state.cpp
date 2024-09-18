#include "game_state.h"
#include "currentsessiondata.h"

#include <iostream>

GameState::GameState(VGame* _game) 
{

    std::cout << "Constructing GameState" << std::endl;
    this->vGame = _game;
}



void GameState::update(const float& dt)
{

}

void GameState::render(sf::RenderTarget* target)
{
}