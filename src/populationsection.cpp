#include "populationsection.h"
#include <iostream>
#include <vector>
#include "technology.h"
#include "attribute.h"

PopulationSection::PopulationSection()
{
    std::cout << "Constructing PopulationSection" << std::endl;
 
}




void PopulationSection::setName(std::string _name) {
    name = _name;
}

std::string PopulationSection::getName() {
    return name;
}

void PopulationSection::addTechnology(Technology* technology) {
    technologies.push_back(technology);
}

void PopulationSection::addAttribute(Attribute* attribute) {
    attributes.push_back(attribute);

}

std::vector<Technology*> PopulationSection::getTechnologies() {
    return technologies;
}
std::vector<Attribute*> PopulationSection::getAttributes() {
    return attributes;
}


