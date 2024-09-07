#include <iostream>
#include <vector>
#include "game_state.h"

GameState::GameState()
{
    std::cout << "Constructing gamestate" << std::endl;
}

void GameState::setCycle(int _cycle)
{
    cycle = _cycle;
}
int GameState::getCycle()
{
    return cycle;
}

void GameState::setNumPlanets(int _numPlanets)
{
    numPlanets = _numPlanets;
}
int GameState::getNumPlanets()
{
    return numPlanets;
}

void GameState::setPlanets(std::vector<Planet *> _planets)
{
    planets = _planets;
}

std::vector<Planet *> GameState::getPlanets()
{
    return planets;
}

GameState *GameState::clone()
{
    GameState *gameState = new GameState();
    gameState->setNumPlanets(numPlanets);
    gameState->setCycle(cycle);
    return gameState;
}

void GameState::setPopulationGroups(std::vector<PopulationGroup *> _populationGroups)
{
    populationGroups = _populationGroups;
}

std::vector<PopulationGroup *> GameState::getPopulationGroups()
{
    return populationGroups;
}

void GameState::setMissions(std::vector<Mission *> _missions)
{
    missions = _missions;
}

std::vector<Mission *> GameState::getMissions()
{
    return missions;
}
