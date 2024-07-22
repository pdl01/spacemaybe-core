#include "attributefactory.h"
#include "attribute.h"

#include <iostream>

AttributeFactory::AttributeFactory()
{

    std::cout << "Constructing AttributeFactory" << std::endl;


}

Attribute* AttributeFactory::create() {
    return create(1);
}

Attribute* AttributeFactory::create(int i) {
    std::cout << "Creating Attribute" << std::endl;
    Attribute* x = new Attribute();
    std::string name = "";
    name.append("a");
    name.append(std::to_string(i));
    x->setName(name);
    return x;
}
