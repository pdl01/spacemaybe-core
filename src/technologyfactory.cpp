#include "technologyfactory.h"
#include <iostream>

TechnologyFactory::TechnologyFactory()
{

    std::cout << "Constructing TechnologyFactory" << std::endl;


}

Technology* TechnologyFactory::create() {
    return create(1);
}

Technology* TechnologyFactory::create(int i) {
    std::cout << "Creating Technolgy" << std::endl;
    Technology* x = new Technology();
    std::string name = "";
    name.append("t");
    name.append(std::to_string(i));
    x->setName(name);
    return x;
}
