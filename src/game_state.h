#ifndef SRC_GAME_STATE_H_
#define SRC_GAME_STATE_H_
#include <vector>
#include "planet.h"
#include "populationgroup.h"
#include "mission.h"

class GameState
{
public:
   GameState();
   void setPlanets(std::vector<Planet *> _planets);
   std::vector<Planet *> getPlanets();

   void setPopulationGroups(std::vector<PopulationGroup *> _populationGroups);
   std::vector<PopulationGroup *> getPopulationGroups();

   void setMissions(std::vector<Mission *> _missions);
   std::vector<Mission *> getMissions();

   void setCycle(int _cycle);
   int getCycle();

   void setNumPlanets(int _numPlanets);
   int getNumPlanets();
   GameState *clone();
   ~GameState();
private:
   int cycle;
   int numPlanets;
   std::vector<Planet *> planets;
   std::vector<PopulationGroup *> populationGroups;
   std::vector<Mission *> missions;
};

#endif