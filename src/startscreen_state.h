#ifndef SRC_STARTSCREEN_STATE_H_
#define SRC_STARTSCREEN_STATE_H_

#include <SFML/Graphics.hpp>
#include <string>
#include <vector> 
#include "state.h"
#include "vgame.h"

class StartScreenState : public State {
 public:
    StartScreenState(VGame* _game);
    ~StartScreenState();
    
    void update(const float& dt);
	void render(sf::RenderTarget* target = NULL);
 private:
    sf::CircleShape mPlayer;
    VGame* vGame;
    void updateInputs();
};
#endif