#include "vgame.h"
#include "game_engine.h"
#include "startscreen_state.h"

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
    this->initStateData();
    this->initStates();
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
void VGame::initStates()
{
	this->states.push(new StartScreenState(&this->currentSessionData,&this->states));
}

void VGame::render()
{
    //mainWindow->clear();
    //mainWindow->draw(mPlayer);
    //mainWindow->display();

	this->mainWindow->clear();

	//Render items
	if (!this->states.empty())
		this->states.top()->render();

	this->mainWindow->display();

}

void VGame::update() {
    //this->updateSFMLEvents();

	if (!this->states.empty())
	{
		if (this->mainWindow->hasFocus())
		{
			this->states.top()->update(0);

			//if (this->states.top()->getQuit())
			//{
			//	this->states.top()->endState();
			//	delete this->states.top();
			//	this->states.pop();
			//}
		}
	}
	//Application end
	else
	{
		//this->endApplication();
		//this->window->close();
	}

}

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

void VGame::initStateData()
{
	this->currentSessionData.window = this->mainWindow;
	//this->stateData.gfxSettings = &this->gfxSettings;
	//this->stateData.supportedKeys = &this->supportedKeys;
	//this->stateData.states = &this->states;
	//this->stateData.gridSize = this->gridSize;
}

VGame::~VGame() {
    delete this->mainWindow;
}