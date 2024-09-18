#ifndef SRC_VGAME_H_
#define SRC_VGAME_H_

#include <SFML/Graphics.hpp>
#include <stack>
#include "state.h"
#include "currentsessiondata.h"
class VGame
{
public:
    VGame();
    void run();
    ~VGame();
    void loadStartScreen();
    void loadMainMenuScreen();
    void loadGameScreen();
    sf::RenderWindow* getMainWindow();
    CurrentSessionData* getCurrentSessionData();

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
};

#endif