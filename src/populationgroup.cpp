#include "populationgroup.h"
#include <iostream>
#include <vector>
#include <string>
#include "technology.h"
#include "attribute.h"
#include "mission.h"

PopulationGroup::PopulationGroup()
{
    std::cout << "Constructing PopulationGroup" << std::endl;
}

void PopulationGroup::setName(std::string _name)
{
    name = _name;
}

std::string PopulationGroup::getName()
{
    return name;
}

void PopulationGroup::addTechnology(Technology *technology)
{
    technologies.push_back(technology);
}

std::vector<Technology *> PopulationGroup::getTechnologies()
{
    return technologies;
}
std::map<std::string,Attribute> PopulationGroup::getAttributes()
{
    return attributes;
}

void PopulationGroup::setAge(int _age)
{
    age = _age;
}
int PopulationGroup::getAge()
{
    return age;
}
void PopulationGroup::incrementAge()
{
    age++;
}

   void PopulationGroup::setTurnEstablished(int _turnEstablished) {turnEstablished = _turnEstablished;}
   int PopulationGroup::getTurnEstablished() { return turnEstablished;}