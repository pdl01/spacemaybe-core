#include <iostream>
#include "game_engine.h"
#include "planetfactory.h"
#include "planet.h"

GameEngine::GameEngine()
{
    exit = false;
    cycle = 23;
    std::cout << "Constructing engine" << std::endl;
    std::cout << "Exit:"<< exit << std::endl;
    std::cout << "Cycle:"<< cycle  << std::endl;
    std::cout << "Constructing engine" << std::endl;

}

void GameEngine::initialize() {
    std::cout << "Initializing" << std::endl;

    PlanetFactory* planetFactory = new PlanetFactory();
    Planet* planet = planetFactory->create();
    std::cout << "Created Planet:" << planet->getName() << std::endl;

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
    if (cycle == 200000) {
        exit = true;
    }

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