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

    void update(const float& dt) = 0;
	void render(sf::RenderTarget* target = NULL) = 0;
private:
    VGame* vGame;

};
#endif