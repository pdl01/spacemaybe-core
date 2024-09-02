#include "populationgroupfactory.h"
#include "populationgroup.h"

#include <iostream>

PopulationGroupFactory::PopulationGroupFactory()
{

    std::cout << "Constructing PopulationSectionFactory" << std::endl;


}

PopulationGroup* PopulationGroupFactory::create() {
    return create(1);
}

PopulationGroup* PopulationGroupFactory::create(int i) {
    std::cout << "Creating PopulationSection" << std::endl;
    PopulationGroup* x = new PopulationGroup();
    std::string name = "";
    name.append("ps");
    name.append(std::to_string(i));
    x->setName(name);

    Technology* technology = technologyFactory.create();
    x->addTechnology(technology);

    Attribute* attribute = attributeFactory.create();
    x->addAttribute(attribute);
    return x;
}
