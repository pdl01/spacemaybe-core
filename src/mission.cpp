#include "mission.h"
#include <iostream>

Mission::Mission()
{

    std::cout << "Constructing Mission" << std::endl;

}


void Mission::setName(std::string _name) {
    name = _name;
}

std::string Mission::getName() {
    return name;
}

void Mission::setStartedOnCycle(int _cycle) {
    startedOnCycle = _cycle;
}

int Mission::getStartedOnCycle() {
    return startedOnCycle;
}

void Mission::setCompletedOnCycle(int _cycle) {
    completedOnCycle = _cycle;
}

int Mission::getCompletedOnCycle() {
    return completedOnCycle;
}

void Mission::setWillCompleteOnCycle(int _cycle) {
    willCompleteOnCycle = _cycle;
}

int Mission::getWillCompleteOnCycle() {
    return willCompleteOnCycle;
}
bool Mission::isCompleted() {
    return completedOnCycle != -1;;
}
bool Mission::isStarted() {
    return startedOnCycle != -1;
}