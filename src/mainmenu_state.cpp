#include "mainmenu_state.h"


#include <iostream>

MainMenuState::MainMenuState(CurrentSessionData* currentSessionData,std::stack<State*>* _states) : State(currentSessionData,_states)
{

    std::cout << "Constructing MainMenuState" << std::endl;

}



void MainMenuState::update(const float& dt)
{
    std::cout << "Update MainMenuState" << std::endl;

}

void MainMenuState::render(sf::RenderTarget* target)
{
    std::cout << "Render MainMenuState" << std::endl;
    this->mPlayer.setRadius(100.f);
    this->mPlayer.setPosition(500.f, 500.f);
    this->mPlayer.setFillColor(sf::Color::Red);
    this->window->draw(this->mPlayer);



 
// Create a text
/*
sf::Font font;
sf::Text text("Loading...");
text.setFont(sf::Font::getDefaultFont());
text.setCharacterSize(30);
text.setStyle(sf::Text::Bold);
text.setFillColor(sf::Color::Red);
this->window->draw(text);
*/
}

MainMenuState::~MainMenuState () {
    
}