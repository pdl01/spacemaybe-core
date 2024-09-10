#ifndef SRC_GROWPOPULATIONONPLANETMISSION_H_
#define SRC_GROWPOPULATIONONPLANETMISSION_H_
#include <string>
#include "mission.h"
#include "populationgroup.h"
#include "planet.h"

class GrowPopulationOnPlanetMission : public Mission {
 public:
    GrowPopulationOnPlanetMission(PopulationGroup* _populationGroup, Planet* _planet, int _startCycle);
    void executeNextCycle(int cycle);

 protected:
 private:
    int defaultGrowthRate = 20; //how many turns before a new geo section is applied by default; will be affected by modifiers
    int defaultNumOfCycles = -1;
    int lastCycleGrown = -1;
    PopulationGroup* populationGroup;
    Planet* planet;

};

#endif