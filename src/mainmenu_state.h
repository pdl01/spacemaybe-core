#ifndef SRC_MAINMENU_STATE_H_
#define SRC_MAINMENU_STATE_H_

#include <SFML/Graphics.hpp>
#include <string>
#include <vector> 
#include "state.h"

class MainMenuState : public State {
 public:
    MainMenuState(CurrentSessionData* currentSessionData,std::stack<State*>* _states);
    ~MainMenuState();
    
    void update(const float& dt);
	void render(sf::RenderTarget* target = NULL);
 private:
    sf::CircleShape mPlayer;
};
#endif