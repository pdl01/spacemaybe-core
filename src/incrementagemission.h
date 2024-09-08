#ifndef SRC_INCREMENTAGEMISSION_H_
#define SRC_INCREMENTAGEMISSION_H_
#include <string>
#include "mission.h"
#include "populationgroup.h"

class IncrementAgeMission : public Mission {
 public:
    IncrementAgeMission(PopulationGroup* _populationGroup,int startCycle);
    void executeNextCycle(int cycle);

 protected:
 private:
    int defaultNumOfCycles = -1;
    PopulationGroup* populationGroup;

};

#endif