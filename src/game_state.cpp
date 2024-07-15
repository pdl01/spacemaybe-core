#include <iostream>
#include <vector> 
#include "game_state.h"


GameState::GameState() {
        std::cout << "Constructing gamestate" << std::endl;
}

void GameState::setCycle(int _cycle ) {
    cycle = _cycle;
}
int GameState::getCycle() {
    return cycle;
}

void GameState::setNumPlanets(int _numPlanets ) {
    numPlanets = _numPlanets;
}
int GameState::getNumPlanets() {
    return numPlanets;
}

void GameState::setPlanets( std::vector<Planet*> _planets) {
    planets = _planets;
}

std::vector<Planet*> GameState::getPlanets() {
    return planets;
}
