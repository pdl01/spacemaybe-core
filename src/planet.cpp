#include "planet.h"
#include "planetarygeosection.h"

#include <iostream>

Planet::Planet()
{

    std::cout << "Constructing Planet" << std::endl;


}


void Planet::executeCycle() {
    //std::cout << "Executing cycle for planet:" << this->name << std::endl;    
}

void Planet::setName(std::string _name) {
    name = _name;
}

std::string Planet::getName() {
    return name;
}

void Planet::setUniverseCoordinate(Coordinate _coordinate) {
    universeCoordinate = _coordinate;
}

Coordinate Planet::getUniverseCoordinate() {
    return universeCoordinate;
}

void Planet::setGeoSections( std::vector<PlanetaryGeoSection*> _geoSections) {
    geoSections = _geoSections;
}
std::vector<PlanetaryGeoSection*> Planet::getGeoSections() {
    return geoSections;
}
