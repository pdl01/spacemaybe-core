#include "incrementagemission.h"

IncrementAgeMission::IncrementAgeMission(PopulationGroup* _populationGroup) {
    this->populationGroup = _populationGroup;
}

void IncrementAgeMission::executeNextCycle(int cycle) {
    populationGroup->incrementAge();
}