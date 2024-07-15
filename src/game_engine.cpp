#include <iostream>
#include "game_engine.h"
#include "planetfactory.h"
#include "planet.h"
#include "game_state.h"

GameEngine::GameEngine()
{
    exit = false;
    //cycle = 23;
    std::cout << "Constructing engine" << std::endl;
    std::cout << "Exit:"<< exit << std::endl;
    //std::cout << "Cycle:"<< cycle  << std::endl;
    std::cout << "Constructing engine" << std::endl;

}

void GameEngine::initialize() {
    std::cout << "Initializing" << std::endl;
    int numOfPlanets = 50;

    gameState = new GameState();
    gameState->setNumPlanets(numOfPlanets);
    gameState->setCycle(0);
    std::vector<Planet*> planets;

    PlanetFactory* planetFactory = new PlanetFactory();
    for (int i=0;i<numOfPlanets;i++) {
        Planet* planet = planetFactory->create(i);
        std::cout << "Created Planet:" << planet->getName() << std::endl;
        planets.push_back(planet);

    }

    gameState->setPlanets(planets);

    for (auto i = gameState->getPlanets().begin(); i != gameState->getPlanets().end(); ++i)  {
        std::cout << *i << " "; 
    }

    for (int i = 0; i < gameState->getNumPlanets(); i++) { 
        // displaying object data 
        std::cout << gameState->getPlanets()[i]->getName() << std::endl;
    } 

}

void GameEngine::start() {
    std::cout << "Starting" << std::endl;
    while (!exit) {
        executeCycle();
    }
}

void GameEngine::executeCycle() {
    int numOfPlanets = gameState->getNumPlanets();
    int cycle = gameState->getCycle();
    std::vector<Planet*> planets = gameState->getPlanets();

    cycle = cycle + 1;
    std::cout << "Executing " << cycle << std::endl;

    for (int i = 0; i < numOfPlanets; i++) { 
        planets[i]->executeCycle();
        // displaying object data 
        std::cout << planets[i]->getName() << std::endl;
    }

    gameState->setCycle(cycle);
    gameState->setPlanets(planets);


    if (cycle == 50) {
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