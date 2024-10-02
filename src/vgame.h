#ifndef SRC_VGAME_H_
#define SRC_VGAME_H_

#include <SFML/Graphics.hpp>
#include <stack>
#include "state.h"
#include "currentsessiondata.h"
#include "game_engine.h"

class VGame
{
public:
    VGame();
    void run();
    ~VGame();
    void loadStartScreen();
    void loadMainMenuScreen();
    void loadGameScreen();
    void startNewGame();
    void continueGame();
    sf::RenderWindow* getMainWindow();
    CurrentSessionData* getCurrentSessionData();
    GameEngine* getGameEngine();

protected:
    void initWindow();
    void initVariables();
    void initStateData();
    void initStates();

private:
    void processEvents();
    void update();
    void render();

private:
    sf::RenderWindow* mainWindow;
    sf::CircleShape mPlayer;
    std::stack<State*> states;
    CurrentSessionData* currentSessionData;
    GameEngine* gameEngine;
};

#endif