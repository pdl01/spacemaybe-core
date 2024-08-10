#include "populationsectionfactory.h"
#include "populationsection.h"

#include <iostream>

PopulationSectionFactory::PopulationSectionFactory()
{

    std::cout << "Constructing PopulationSectionFactory" << std::endl;


}

PopulationSection* PopulationSectionFactory::create() {
    return create(1);
}

PopulationSection* PopulationSectionFactory::create(int i) {
    std::cout << "Creating PopulationSection" << std::endl;
    PopulationSection* x = new PopulationSection();
    std::string name = "";
    name.append("ps");
    name.append(std::to_string(i));
    x->setName(name);

    Technology* technology = technologyFactory.create();
    x->addTechnology(technology);

    Attribute* attribute = attributeFactory.create();
    x->addAttribute(attribute);

    //build the attributes and technologies
    return x;
}
