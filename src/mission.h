#ifndef SRC_MISSION_H_
#define SRC_MISSION_H_
#include <string>

class Mission {
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
    
 protected:
 private:
    std::string name;
    int startedOnCycle;
    int completedOnCycle;
    int willCompleteOnCycle;


};

#endif