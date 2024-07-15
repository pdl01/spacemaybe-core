#ifndef SRC_GAME_STATE_H_
#define SRC_GAME_STATE_H_
#include <vector> 
#include "planet.h"


class GameState {
 public:
    GameState();
    void setPlanets( std::vector<Planet*> _planets);
    std::vector<Planet*> getPlanets();

    void setCycle(int _cycle);
    int getCycle();

    void setNumPlanets(int _numPlanets);
    int getNumPlanets();

 private:
    int cycle;
    int numPlanets;
    std::vector<Planet*> planets;

};

#endif