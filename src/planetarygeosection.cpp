#include "planetarygeosection.h"
#include <iostream>

PlanetaryGeoSection::PlanetaryGeoSection()
{

    std::cout << "Constructing PlanetaryGeoSection" << std::endl;

}
PlanetaryGeoSection::PlanetaryGeoSection(int _geoSectionid)
{
    this->geoSectionId = _geoSectionid;
    std::cout << "Constructing PlanetaryGeoSection:"<< this->geoSectionId << std::endl;

}

PopulationGroup* PlanetaryGeoSection::getOwner() {
    return owner;
}

void PlanetaryGeoSection::setOwner(PopulationGroup* _owner) {
    owner = _owner;
}


