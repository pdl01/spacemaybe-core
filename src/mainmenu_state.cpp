#include "mainmenu_state.h"


#include <iostream>

MainMenuState::MainMenuState(VGame* _game) 
{

    //std::cout << "Constructing MainMenuState" << std::endl;
    this->vGame = _game;
    //this->states = _states;
    //std::cout << "Constructing 2 MainMenuState" << std::endl;

    //this->currentSessionData = _currentSessionData;
        //std::cout << "Constructing 3 MainMenuState" << std::endl;

    //this->window = _currentSessionData->window;
    //std::cout << "Constructing 4 MainMenuState" << std::endl;

}



void MainMenuState::update(const float& dt)
{
    //std::cout << "Update MainMenuState" << std::endl;
    this->updateInputs();
}

void MainMenuState::updateInputs() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->mPlayer.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*this->vGame->getMainWindow())))){
        
        //std::cout << "left mouse pressed MainMenuState" << std::endl;
        
        //this->states->push(new MainMenuState(this->currentSessionData,this->states));
        this->vGame->startNewGame();
       //this->vGame->loadGameScreen();
    }
}

void MainMenuState::render(sf::RenderTarget* target)
{
    //std::cout << "Render MainMenuState" << std::endl;
    this->mPlayer.setRadius(100.f);
    this->mPlayer.setPosition(500.f, 500.f);
    this->mPlayer.setFillColor(sf::Color::Red);
    this->vGame->getMainWindow()->draw(this->mPlayer);



 
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