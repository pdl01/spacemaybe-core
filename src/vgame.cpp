#include "vgame.h"

VGame::VGame()
    : mWindow(sf::VideoMode(1024, 768), "SFML Application"), mPlayer()
{
    mPlayer.setRadius(40.f);
    mPlayer.setPosition(100.f, 100.f);
    mPlayer.setFillColor(sf::Color::Cyan);
}
void VGame::run()
{
    while (mWindow.isOpen())
    {
        processEvents();
        update();
        render();
    }
}

void VGame::processEvents()
{
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            mWindow.close();
    }
}

void VGame::render()
{
    mWindow.clear();
    mWindow.draw(mPlayer);
    mWindow.display();
}

void VGame::update() {}