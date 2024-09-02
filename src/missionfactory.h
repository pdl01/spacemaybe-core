#ifndef SRC_MISSION_FACTORY_H_
#define SRC_MISSION_FACTORY_H_

#include "mission.h"
#include <string>

class MissionFactory {
 public:
    MissionFactory();
    
    Mission* create();
    Mission* create(int i);
    Mission* create(std::string _name, int startCycle, int willCompleteOnCycle);
    Mission* createMissionFromResource();
  
 protected:
 private:
    
    
    
};

#endif