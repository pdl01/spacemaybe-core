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
private:
    VGame* vGame;
    sf::View view;
    sf::FloatRect mWorldBounds;
    sf::Texture texture;
    sf::CircleShape top_right_icon;
    sf::CircleShape bottom_right_icon;
    sf::CircleShape top_left_icon;
    sf::CircleShape bottom_left_icon;
};
#endif