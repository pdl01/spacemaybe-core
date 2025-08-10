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

    GameObjs* getGameObjs();
    void executeCycle();
    bool shouldExit();
    
 protected:
 private:
    bool exit;

    GameObjs* gameObjs;
    int buildPlanetCoordinateComponent(int _universeMaxUnitPerDimension, int _minimumDistanceFromCenter);
    
};

#endif