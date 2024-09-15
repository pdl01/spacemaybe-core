#ifndef SRC_CURRENTSESSIONDATA_H_
#define SRC_CURRENTSESSIONDATA_H_
#include <SFML/Graphics.hpp>
class CurrentSessionData
{
public:
    CurrentSessionData();

    // Variables
    float gridSize;
    sf::RenderWindow *window;
    //GraphicsSettings *gfxSettings;
    //std::map<std::string, int> *supportedKeys;
    //std::stack<State *> *states;
};
#endif