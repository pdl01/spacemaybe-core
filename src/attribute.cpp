#include "attribute.h"
#include <iostream>

Attribute::Attribute()
{

    std::cout << "Constructing Attribute" << std::endl;


}




void Attribute::setName(std::string _name) {
    name = _name;
}

std::string Attribute::getName() {
    return name;
}

void Attribute::setLevel(int _level) {
    level = _level;
}

int Attribute::getLevel() {
    return level;
}

