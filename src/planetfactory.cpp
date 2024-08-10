#include "planetfactory.h"
#include <iostream>
#include "populationsection.h"

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

    PopulationSection* populationSection = populationSectionFactory.create();
    x->addPopulationSection(populationSection);

    return x;
}
