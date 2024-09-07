#ifndef SRC_INCREMENTAGEMISSION_H_
#define SRC_INCREMENTAGEMISSION_H_
#include <string>
#include "mission.h"
#include "populationgroup.h"

class IncrementAgeMission : public Mission {
 public:
    IncrementAgeMission(PopulationGroup* _populationGroup);
    void executeNextCycle(int cycle);

 protected:
 private:
 
    PopulationGroup* populationGroup;

};

#endif