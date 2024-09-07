#ifndef SRC_MISSION_H_
#define SRC_MISSION_H_
#include <string>
#include "abstractmission.h"

class Mission : public AbstractMission {
 public:
    Mission();
    void setName(std::string _name);
    std::string getName();
    void setStartedOnCycle(int _cycle);
    int getStartedOnCycle();
    void setCompletedOnCycle(int _cycle);
    int getCompletedOnCycle();
    void setWillCompleteOnCycle(int _cycle);
    int getWillCompleteOnCycle();
    bool isCompleted();
    bool isStarted();
   //virtual void executeNextCycle(int cycle) = 0;

 protected:
 private:
    std::string name;
    int startedOnCycle;
    int completedOnCycle;
    int willCompleteOnCycle;


};

#endif