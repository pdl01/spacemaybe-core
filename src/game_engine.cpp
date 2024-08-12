#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game_engine.h"
#include "planetfactory.h"
#include "planet.h"
#include "game_state.h"
#include "technologyfactory.h"
#include "attributefactory.h"
#include "populationsectionfactory.h"
#include "coordinate.h"

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
    int numOfPopulatedPlanets = 1;
    int universeMaxUnitPerDimension = 14000;  //14000 in each direction
    int minimumDistanceFromCenter = 2000; //minimum distance from [0,0,0]

    gameState = new GameState();
    gameState->setNumPlanets(numOfPlanets);
    gameState->setCycle(0);
    std::vector<Planet*> planets;

    PlanetFactory planetFactory;

    PopulationSectionFactory populationSectionFactory;

  
    std::srand(std::time(nullptr));

    for (int i=0;i<numOfPlanets;i++) {
        Planet* planet = planetFactory.create(i);

        //assign coordinates
        

        //build random coordinate
        //is coordinate already there
        //is coordinate too close to other coordinates
    //    int random_value = std::rand();
    //    int range = universeMaxUnitPerDimension - minimumDistanceFromCenter + 1;
    //    int num = random_value % range + minimumDistanceFromCenter;
        int planet_x = this->buildPlanetCoordinateComponent(universeMaxUnitPerDimension,minimumDistanceFromCenter);
        //randomly set to negative or positive
        
        int planet_y = this->buildPlanetCoordinateComponent(universeMaxUnitPerDimension,minimumDistanceFromCenter);
        //randomly set to negative or positive

        int planet_z = this->buildPlanetCoordinateComponent(universeMaxUnitPerDimension,minimumDistanceFromCenter);
        //randomly set to negative or positive

        Coordinate planetCoordinate =  Coordinate(planet_x,planet_y,planet_z,"universe");
        planet->setUniverseCoordinate(planetCoordinate);
        
        std::cout << "Created Planet:" << planet->getName() << "[x="<<planet_x << ",y="<< planet_y << ",z=" << planet_z << "]" << std::endl;

        planets.push_back(planet);
    }

    for (int i=0;i<numOfPopulatedPlanets;i++) {
        //randomly select a planet and add population sections to it
        PopulationSection* pa = populationSectionFactory.create();

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
int GameEngine::buildPlanetCoordinateComponent(int _universeMaxUnitPerDimension, int _minimumDistanceFromCenter) {
    int random_value = std::rand();
    int range = _universeMaxUnitPerDimension - _minimumDistanceFromCenter + 1;
    int num = random_value % range + _minimumDistanceFromCenter;
    int second_random_value = std::rand();
    if (second_random_value % 2 == 0) {
        num = num * -1;
    }
    return num;
}
void GameEngine::start() {
    std::cout << "Starting" << std::endl;
    while (!exit) {
        executeCycle();
        
        //clone the game state and add to the vector
        //  
    }
    delete (this->gameState);
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
        //exit = true;
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