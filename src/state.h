#ifndef SRC_STATE_H_
#define SRC_STATE_H_

#include <SFML/Graphics.hpp>
#include <string>
#include <vector> 
#include "currentsessiondata.h"
#include <stack>

class State {
 public:
    State();
    virtual ~State();
           
    virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = NULL) = 0;
 protected:
    CurrentSessionData* currentSessionData;
	std::stack<State*>* states;
	sf::RenderWindow* window;
	bool quit;
	bool paused;

};
#endif