#ifndef SRC_STARTSCREEN_STATE_H_
#define SRC_STARTSCREEN_STATE_H_

#include <SFML/Graphics.hpp>
#include <string>
#include <vector> 
#include "state.h"

class StartScreenState : public State {
 public:
    StartScreenState(CurrentSessionData* currentSessionData,std::stack<State*>* _states);
    ~StartScreenState();
    
    void update(const float& dt);
	void render(sf::RenderTarget* target = NULL);
 private:
    sf::CircleShape mPlayer;

    void updateInputs();
};
#endif