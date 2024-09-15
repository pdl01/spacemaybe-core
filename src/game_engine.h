#ifndef SRC_GAME_ENGINE_H_
#define SRC_GAME_ENGINE_H_
#include <vector> 
#include "planet.h"
#include "game_objs.h"

class GameEngine {
 public:
    GameEngine();
    void initialize();
    void start();
    ~GameEngine();

 protected:
 private:
    bool exit;

    void executeCycle();
    GameObjs* gameObjs;
    int buildPlanetCoordinateComponent(int _universeMaxUnitPerDimension, int _minimumDistanceFromCenter);
    
};

#endif