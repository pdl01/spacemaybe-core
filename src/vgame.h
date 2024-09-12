#include <SFML/Graphics.hpp>

class VGame
{
public:
    VGame();
    void run();

private:
    void processEvents();
    void update();
    void render();

private:
    sf::RenderWindow mWindow;
    sf::CircleShape mPlayer;
};