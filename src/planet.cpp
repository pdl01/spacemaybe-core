#include "planet.h"
#include <iostream>

Planet::Planet()
{

    std::cout << "Constructing Planet" << std::endl;


}


void Planet::executeCycle() {
    std::cout << "Executing cycle for planet:" << this->name << std::endl;    
}

void Planet::setName(std::string _name) {
    name = _name;
}

std::string Planet::getName() {
    return name;
}

void Planet::addPopulationSection (PopulationSection* populationSection) {
    populationSections.push_back(populationSection);
}

void Planet::setUniverseCoordinate(Coordinate _coordinate) {
    universeCoordinate = _coordinate;
}

Coordinate Planet::getUniverseCoordinate() {
    return universeCoordinate;
}


