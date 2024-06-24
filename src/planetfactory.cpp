#include "planetfactory.h"
#include <iostream>

PlanetFactory::PlanetFactory()
{

    std::cout << "Constructing PlanetFacory" << std::endl;


}

Planet* PlanetFactory::create() {
    std::cout << "Creating Planet" << std::endl;
    Planet* x = new Planet();
    x->setName("p1");
    return x;
}
