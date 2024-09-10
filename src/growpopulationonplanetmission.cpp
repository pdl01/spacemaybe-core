#include "growpopulationonplanetmission.h"
#include <iostream>

GrowPopulationOnPlanetMission::GrowPopulationOnPlanetMission(PopulationGroup *_populationGroup, Planet *_planet, int _startCycle)
{
    this->setName("GrowPopulation:" + _populationGroup->getName() + " on Planet " + _planet->getName());
    this->setStartedOnCycle(_startCycle);
    this->setWillCompleteOnCycle(this->defaultNumOfCycles);
    this->populationGroup = _populationGroup;
    this->planet = _planet;
    this->lastCycleGrown = _startCycle;
    // assign population group to a geosection on planet
    // for (auto & element : vector) {
    //     element.doSomething();
    // }
    bool assigned = false;
    for (auto &geoSection : planet->getGeoSections())
    {
        if (!assigned && geoSection->getOwner() == NULL)
        {
            geoSection->setOwner(_populationGroup);
            assigned = true;
        }
    }
}

void GrowPopulationOnPlanetMission::executeNextCycle(int cycle)
{
    std::cout << "GrowPopulationOnPlanetMission " << populationGroup->getName() << " planet:" << planet->getName() << std::endl;

    int modifedGrowthRate = defaultGrowthRate;
    if (this->lastCycleGrown + modifedGrowthRate < cycle)
    {
        bool assigned = false;
        for (auto &geoSection : planet->getGeoSections())
        {
            if (!assigned && geoSection->getOwner() == NULL)
            {
                geoSection->setOwner(populationGroup);
                assigned = true;
            }
        }
        if (!assigned) {
            std::cout << "GrowPopulationOnPlanetMission (unable to grow)(cycle:" << cycle << ")" << populationGroup->getName() << " planet:" << planet->getName() << std::endl;
        }
    }
   
}