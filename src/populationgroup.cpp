#include "populationgroup.h"
#include <iostream>
#include <vector>
#include "technology.h"
#include "attribute.h"
#include "mission.h"

PopulationGroup::PopulationGroup()
{
    std::cout << "Constructing PopulationGroup" << std::endl;
 
}




void PopulationGroup::setName(std::string _name) {
    name = _name;
}

std::string PopulationGroup::getName() {
    return name;
}

void PopulationGroup::addTechnology(Technology* technology) {
    technologies.push_back(technology);
}

void PopulationGroup::addAttribute(Attribute* attribute) {
    attributes.push_back(attribute);

}

std::vector<Technology*> PopulationGroup::getTechnologies() {
    return technologies;
}
std::vector<Attribute*> PopulationGroup::getAttributes() {
    return attributes;
}




