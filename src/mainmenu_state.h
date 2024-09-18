#ifndef SRC_MAINMENU_STATE_H_
#define SRC_MAINMENU_STATE_H_

#include <SFML/Graphics.hpp>
#include <string>
#include <vector> 
#include "state.h"
#include "vgame.h"

class MainMenuState : public State {
 public:
    MainMenuState(VGame* _game);
    ~MainMenuState();
    
    void update(const float& dt);
	void render(sf::RenderTarget* target = NULL);
 private:
    sf::CircleShape mPlayer;
    VGame* vGame;

};
#endif