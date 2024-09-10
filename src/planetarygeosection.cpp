#include "planetarygeosection.h"
#include <iostream>

PlanetaryGeoSection::PlanetaryGeoSection()
{

    std::cout << "Constructing PlanetaryGeoSection" << std::endl;

}

PopulationGroup* PlanetaryGeoSection::getOwner() {
    return owner;
}

void PlanetaryGeoSection::setOwner(PopulationGroup* _owner) {
    owner = _owner;
}


