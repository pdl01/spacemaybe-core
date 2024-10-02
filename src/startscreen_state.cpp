#include "startscreen_state.h"
#include "mainmenu_state.h"

#include <iostream>

StartScreenState::StartScreenState(VGame* _game)
{

    std::cout << "Constructing StartScreenState" << std::endl;
    this->vGame = _game;
    //this->states = _states;
    //this->currentSessionData = currentSessionData;
    //this->window = _currentSessionData->window;

}



void StartScreenState::update(const float& dt)
{
    //std::cout << "Update StartScreenState" << std::endl;
    this->updateInputs();
}

void StartScreenState::updateInputs() {


    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->mPlayer.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*this->vGame->getMainWindow())))){
        
        //std::cout << "left mouse pressed StartScreenState" << std::endl;
        
        //this->states->push(new MainMenuState(this->currentSessionData,this->states));
        this->vGame->loadMainMenuScreen();
    }
}

void StartScreenState::render(sf::RenderTarget* target)
{
    //std::cout << "Render 1 StartScreenState" << std::endl;
    this->mPlayer.setRadius(180.f);
    //std::cout << "Render 2 StartScreenState" << std::endl;

    this->mPlayer.setPosition(100.f, 100.f);
    this->mPlayer.setFillColor(sf::Color::Cyan);
    this->vGame->getMainWindow()->draw(this->mPlayer);
    //std::cout << "Render 3 StartScreenState" << std::endl;



 
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

StartScreenState::~StartScreenState () {
    
}