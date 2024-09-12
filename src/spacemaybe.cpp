#include <iostream>
#include "game_engine.h"
//#include "vgame.h"

int main()
{
    std::cout << "vgame starting" << std::endl;

    //VGame vgame;
    //vgame.run();

    std::cout << "main starting" << std::endl;


    GameEngine game;
    game.initialize();
    game.start();
}
