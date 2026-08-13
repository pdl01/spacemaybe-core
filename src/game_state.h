#ifndef SRC_GAMESTATE_STATE_H_
#define SRC_GAMESTATE_STATE_H_

#include <SFML/Graphics.hpp>
#include <string>
#include <vector> 
#include "state.h"
#include "vgame.h"

class GameState : public State {
 public:
    GameState(VGame* _game);
    ~GameState();

    void update(const float& dt);
	void render(sf::RenderTarget* target = NULL);
    void renderControlView(sf::RenderWindow* win);
    void renderInfoView(sf::RenderWindow* win);
    void renderMainView(sf::RenderWindow* win);


private:
    VGame* vGame;
    sf::View mainView;
    sf::View controlView;
    sf::View infoView;
    bool showPlanetNames;
    bool fontLoaded;
    bool wasMousePressed;
    sf::Font font;
    
    
    sf::FloatRect mWorldBounds;
    sf::Texture texture;
    sf::CircleShape top_right_icon;
    sf::CircleShape bottom_right_icon;
    sf::CircleShape top_left_icon;
    sf::CircleShape bottom_left_icon;
    int gsCycle;
    int incrementGECycleAfterGSCcycle;
};
#endif