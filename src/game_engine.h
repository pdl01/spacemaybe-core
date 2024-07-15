#ifndef SRC_GAME_ENGINE_H_
#define SRC_GAME_ENGINE_H_
#include <vector> 
#include "planet.h"
#include "game_state.h"

class GameEngine {
 public:
    GameEngine();
    void initialize();
    void start();

//    void setExit(bool _exit);
//    bool getExit();
    
//    void stop();
//void start();
//    
 protected:
 private:
    bool exit;
    //int cycle;
    //std::vector<Planet*> planets;
    void executeCycle();
    GameState* gameState;

    
};

#endif