#include "technology.h"
#include <iostream>

Technology::Technology()
{

    std::cout << "Constructing Technology" << std::endl;


}




void Technology::setName(std::string _name) {
    name = _name;
}

std::string Technology::getName() {
    return name;
}

void Technology::setLevel(int _level) {
    level = _level;
}

int Technology::getLevel() {
    return level;
}

