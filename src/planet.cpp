#include "planet.h"
#include <iostream>

Planet::Planet()
{

    std::cout << "Constructing PlanetFacory" << std::endl;


}


void Planet::execute() {

}

void Planet::setName(char* _name) {
    name = _name;
}

char* Planet::getName() {
    return name;
}
