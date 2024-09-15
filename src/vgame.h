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
protected:
    void initWindow();
    void initVariables();
    void initStateData();

private:
    void processEvents();
    void update();
    void render();

private:
    sf::RenderWindow *mainWindow;
    sf::CircleShape mPlayer;
    std::stack<State*> states;
    CurrentSessionData currentSessionData;
};