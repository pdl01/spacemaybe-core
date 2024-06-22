#include <iostream>
#include "game_engine.h"

GameEngine::GameEngine()
{
    exit = false;
    cycle = 23;
    std::cout << "Constructing engine" << std::endl;
    std::cout << "Exit:"<< exit << std::endl;
    std::cout << "Cycle:"<< cycle  << std::endl;
    std::cout << "Constructing engine" << std::endl;

}

void GameEngine::start() {
    std::cout << "Starting" << std::endl;
    while (!exit) {
        execute();
    }
}

void GameEngine::execute() {
    cycle = cycle + 1;
    std::cout << "Executing " << cycle << std::endl;

}
/*
void setExit(bool _exit)
{
    //exit = _exit;
}

bool getExit()
{
    return false;
}

void stop() {
    setExit(true);
}
*/