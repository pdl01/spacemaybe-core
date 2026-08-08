#include "game_state.h"
#include "currentsessiondata.h"
#include <SFML/Window/Mouse.hpp>


#include <iostream>

GameState::GameState(VGame *_game)
{
    std::cout << "Constructing GameState" << std::endl;
    this->gsCycle = 0;
    //will be set by game speed;
    this->incrementGECycleAfterGSCcycle = 1000;
    this->vGame = _game;
    texture.loadFromFile("/home/phil/Documents/Projects/spacemaybe/code/spacemaybe/src/Resources/Images/Backgrounds/bg1.png");
   


   //create a scenegraph;
   //go through all planets and populate the scenenode 
    GameEngine *gameEngine = this->vGame->getGameEngine();

 //build a scene graph based on the current gameObjs;
    for (auto i = gameEngine->getGameObjs()->getPlanets().begin(); i != gameEngine->getGameObjs()->getPlanets().end(); ++i)  {
        //add the planet to the scene graph
    }

}

void GameState::update(const float &dt)
{    
    //std::cout << "GameState:Update" << std::endl;
    GameEngine *gameEngine = this->vGame->getGameEngine();
    if (this->gsCycle > this->incrementGECycleAfterGSCcycle) {
        gameEngine->executeCycle();
        this->gsCycle = 0;

    } else {
        this->gsCycle++;
    }

   
    this->top_left_icon.setRadius(20.f);
    this->top_left_icon.setPosition(0.f, 0.f);
    this->top_left_icon.setFillColor(sf::Color::Red);
    
    this->top_right_icon.setRadius(20.f);
    this->top_right_icon.setPosition(this->mainView.getSize().x-40.f, 0.f);
    this->top_right_icon.setFillColor(sf::Color::Black);

    this->bottom_right_icon.setRadius(20.f);
    this->bottom_right_icon.setPosition(this->mainView.getSize().x-40.f, this->mainView.getSize().y-40.f);
    this->bottom_right_icon.setFillColor(sf::Color::Green);

    this->bottom_left_icon.setRadius(20.f);
    this->bottom_left_icon.setPosition(0.f, this->mainView.getSize().y-40.f);
    this->bottom_left_icon.setFillColor(sf::Color::Magenta);
    //create the four absoloute corners at the world boundries


    

    sf::Vector2i mousePos = sf::Mouse::getPosition();
    sf::Vector2f mousePosF = this->vGame->getMainWindow()->mapPixelToCoords(mousePos);
    std::cout << "x:" << mousePosF.x << "y:" << mousePosF.y << "\n";
}

void GameState::render(sf::RenderTarget *target)
{
    //std::cout << "GameState:Render" << std::endl;

    this->mainView.reset(sf::FloatRect(0,0,2048,1400));
    this->mWorldBounds = sf::FloatRect(0.f,0.f,this->mainView.getSize().x,2000.f);
    
    texture.setRepeated(true);
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sf::IntRect textureRect(mWorldBounds);
    sprite.setTextureRect(textureRect);
    sprite.setPosition(0.f, 0.f);

    this->vGame->getMainWindow()->clear();
    this->vGame->getMainWindow()->setView(this->mainView);

    // Draw the textured sprite
    this->vGame->getMainWindow()->draw(sprite);
    //this->vGame->getMainWindow()->display();
    //this->view.rotate(45);
    //this->view.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
    this->mainView.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
    

    //paint the 4 corners
    //move the view port to be around the mouse
    this->vGame->getMainWindow()->draw(this->top_left_icon);
    this->vGame->getMainWindow()->draw(this->top_right_icon);
    this->vGame->getMainWindow()->draw(this->bottom_right_icon);
    this->vGame->getMainWindow()->draw(this->bottom_left_icon);

    this->miniView.reset(sf::FloatRect(-3,3,100,100));
    this->vGame->getMainWindow()->setView(this->miniView);
    //TODO:draw the background
    sf::RectangleShape minibkg;
    minibkg.setFillColor(sf::Color::Blue);
    minibkg.setPosition(0,0);
    minibkg.setSize(sf::Vector2f(100, 100));


    this->vGame->getMainWindow()->draw(minibkg);
    this->miniView.setViewport(sf::FloatRect(0.f, 0.75f, 0.25f, 0.25f));
    this->vGame->getMainWindow()->draw(this->top_left_icon);

}

GameState::~GameState()
{
}