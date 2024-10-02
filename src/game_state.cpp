#include "game_state.h"
#include "currentsessiondata.h"

#include <iostream>

GameState::GameState(VGame *_game)
{
    std::cout << "Constructing GameState" << std::endl;
    this->vGame = _game;
texture.loadFromFile("/home/phil/Documents/Projects/spacemaybe/code/spacemaybe/src/Resources/Images/Backgrounds/bg1.png");
   
}

void GameState::update(const float &dt)
{    
    std::cout << "GameState:Update" << std::endl;
    GameEngine *gameEngine = this->vGame->getGameEngine();

    this->top_left_icon.setRadius(20.f);
    this->top_left_icon.setPosition(0.f, 0.f);
    this->top_left_icon.setFillColor(sf::Color::Red);
    
    this->top_right_icon.setRadius(20.f);
    this->top_right_icon.setPosition(this->view.getSize().x-40.f, 0.f);
    this->top_right_icon.setFillColor(sf::Color::Blue);

    this->bottom_right_icon.setRadius(20.f);
    this->bottom_right_icon.setPosition(this->view.getSize().x-40.f, this->view.getSize().y-40.f);
    this->bottom_right_icon.setFillColor(sf::Color::Green);

    this->bottom_left_icon.setRadius(20.f);
    this->bottom_left_icon.setPosition(0.f, this->view.getSize().y-40.f);
    this->bottom_left_icon.setFillColor(sf::Color::Magenta);
    //create the four absoloute corners at the world boundries
}

void GameState::render(sf::RenderTarget *target)
{
    std::cout << "GameState:Render" << std::endl;

    this->view.reset(sf::FloatRect(0,0,2048,1400));
    this->mWorldBounds = sf::FloatRect(0.f,0.f,this->view.getSize().x,2000.f);
    
    texture.setRepeated(true);
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sf::IntRect textureRect(mWorldBounds);
    sprite.setTextureRect(textureRect);
    sprite.setPosition(0.f, 0.f);

    this->vGame->getMainWindow()->clear();

    // Draw the textured sprite
    this->vGame->getMainWindow()->draw(sprite);
    //this->vGame->getMainWindow()->display();
    //this->view.rotate(45);
    this->view.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
    //this->view.setViewport(sf::FloatRect(0.f, 0.f, 0.5, 0.5));

    this->vGame->getMainWindow()->setView(this->view);

    //paint the 4 corners
    //move the view port to be around the mouse
    this->vGame->getMainWindow()->draw(this->top_left_icon);
    this->vGame->getMainWindow()->draw(this->top_right_icon);
    this->vGame->getMainWindow()->draw(this->bottom_right_icon);
    this->vGame->getMainWindow()->draw(this->bottom_left_icon);

}

GameState::~GameState()
{
}