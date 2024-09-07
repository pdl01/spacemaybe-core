#include "planetfactory.h"
#include <iostream>
#include <vector>

PlanetFactory::PlanetFactory()
{

    std::cout << "Constructing PlanetFactory" << std::endl;


}

Planet* PlanetFactory::create() {
    return create(1);
}

Planet* PlanetFactory::create(int i) {
    std::cout << "Creating Planet" << std::endl;
    Planet* x = new Planet();
    std::string name = "";
    name.append("p");
    name.append(std::to_string(i));
    x->setName(name);
    std::vector<PlanetaryGeoSection*> geoSections;
    for (int i=0;i<numOfGeoSections;i++) {
        PlanetaryGeoSection* geoSection = createPlanetaryGeoSection();
        geoSections.push_back(geoSection);
    }
    x->setGeoSections(geoSections);
    std::cout << "Completed Creating Planet" << std::endl;

    return x;
}

PlanetaryGeoSection* PlanetFactory::createPlanetaryGeoSection() {
    PlanetaryGeoSection* pgs = new PlanetaryGeoSection();
    return pgs;
}

