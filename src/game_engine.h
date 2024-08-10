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
 protected:
 private:
    bool exit;

    void executeCycle();
    GameState* gameState;

    
};

#endif