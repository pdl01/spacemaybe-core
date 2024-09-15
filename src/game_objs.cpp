#include <iostream>
#include <vector>
#include "game_objs.h"

GameObjs::GameObjs()
{
    std::cout << "Constructing gamestate" << std::endl;
}

void GameObjs::setCycle(int _cycle)
{
    cycle = _cycle;
}
int GameObjs::getCycle()
{
    return cycle;
}

void GameObjs::setNumPlanets(int _numPlanets)
{
    numPlanets = _numPlanets;
}
int GameObjs::getNumPlanets()
{
    return numPlanets;
}

void GameObjs::setPlanets(std::vector<Planet *> _planets)
{
    planets = _planets;
}

std::vector<Planet *> GameObjs::getPlanets()
{
    return planets;
}

GameObjs *GameObjs::clone()
{
    GameObjs *gameObjs = new GameObjs();
    gameObjs->setNumPlanets(numPlanets);
    gameObjs->setCycle(cycle);
    return gameObjs;
}

void GameObjs::setPopulationGroups(std::vector<PopulationGroup *> _populationGroups)
{
    populationGroups = _populationGroups;
}

std::vector<PopulationGroup *> GameObjs::getPopulationGroups()
{
    return populationGroups;
}

void GameObjs::setMissions(std::vector<Mission *> _missions)
{
    missions = _missions;
}

std::vector<Mission *> GameObjs::getMissions()
{
    return missions;
}

GameObjs::~GameObjs() {
    /*
    while(!missions.empty()) {
        delete missions.back();
        missions.pop_back();
    }
    while(!planets.empty()) {
        delete planets.back();
        planets.pop_back();
    }
    while(!populationGroups.empty()) {
        delete populationGroups.back();
        populationGroups.pop_back();
    }
    */
}