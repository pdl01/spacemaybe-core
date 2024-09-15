#include <SFML/Graphics.hpp>

class VGame
{
public:
    VGame();
    void run();
protected:
    void initWindow();
    void initVariables();

private:
    void processEvents();
    void update();
    void render();

private:
    sf::RenderWindow *mainWindow;
    sf::CircleShape mPlayer;

    
};