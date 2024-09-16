#ifndef SRC_GAMESTATE_STATE_H_
#define SRC_GAMESTATE_STATE_H_

#include <SFML/Graphics.hpp>
#include <string>
#include <vector> 
#include "state.h"

class GameState : public State {
 public:
    GameState(CurrentSessionData* currentSessionData,std::stack<State*>* _states);

    void update(const float& dt) = 0;
	void render(sf::RenderTarget* target = NULL) = 0;
};
#endif