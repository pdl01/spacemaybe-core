#include "incrementagemission.h"
#include <iostream>

IncrementAgeMission::IncrementAgeMission(PopulationGroup* _populationGroup, int startCycle) {
    this->setName("Increment Age");
    this->setStartedOnCycle(startCycle);
    this->setWillCompleteOnCycle(this->defaultNumOfCycles);
    this->populationGroup = _populationGroup;
}

void IncrementAgeMission::executeNextCycle(int cycle) {
    populationGroup->incrementAge();
    std::cout << "IncrementAgeMission " << populationGroup->getName() << " age:" <<  populationGroup->getAge() << std::endl;

}
