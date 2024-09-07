#ifndef SRC_ABSMISSION_H_
#define SRC_ABSMISSION_H_
#include <string>

class AbstractMission {
public:
    virtual ~AbstractMission() {}
    virtual void executeNextCycle(int cycle) = 0;
    
    virtual void setName(std::string _name) = 0;
    virtual std::string getName() =0;
    virtual void setStartedOnCycle(int _cycle) =0;
    virtual int getStartedOnCycle() = 0;
    virtual void setCompletedOnCycle(int _cycle) =0;
    virtual int getCompletedOnCycle() = 0;
    virtual void setWillCompleteOnCycle(int _cycle) =0;
    virtual int getWillCompleteOnCycle() = 0;
    virtual bool isCompleted() = 0;
    virtual bool isStarted() = 0;

};

#endif