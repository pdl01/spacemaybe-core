#include "vgame.h"
#include "game_engine.h"

/*
VGame::VGame()
    : mainWindow(sf::VideoMode(1024, 768), "Space Maybe"), mPlayer()
{
    mPlayer.setRadius(40.f);
    mPlayer.setPosition(100.f, 100.f);
    mPlayer.setFillColor(sf::Color::Cyan);
}
*/
VGame::VGame() {
    this->initVariables();
    this->initWindow();
}
void VGame::run()
{

    GameEngine game;
    //game.initialize();
    //game.start();

    while (mainWindow->isOpen())
    {
        processEvents();
        update();
        render();
    }
}

void VGame::processEvents()
{
    sf::Event event;
    while (mainWindow->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            mainWindow->close();
    }
}

void VGame::render()
{
    mainWindow->clear();
    mainWindow->draw(mPlayer);
    mainWindow->display();
}

void VGame::update() {}

void VGame::initVariables() {
    this->mainWindow = NULL;
}
void VGame::initWindow() {
    this->mainWindow = new sf::RenderWindow(
			sf::VideoMode(1024, 768),
			"Space Maybe",
			sf::Style::Titlebar | sf::Style::Close);

			//this->gfxSettings.contextSettings); 
}