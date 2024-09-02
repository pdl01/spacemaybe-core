#include "missionfactory.h"
#include "mission.h"

#include <iostream>

MissionFactory::MissionFactory()
{

    std::cout << "Constructing MissionFactory" << std::endl;
}

Mission* MissionFactory::create()
{
    return create(1);
}

Mission* MissionFactory::create(int i)
{
    std::cout << "Creating Mission" << std::endl;
    Mission *x = new Mission();
    std::string name = "";
    name.append("a");
    name.append(std::to_string(i));
    x->setName(name);
    x->setStartedOnCycle(1);
    x->setWillCompleteOnCycle(-1);
    return x;
}

Mission* MissionFactory::create(std::string _name, int startCycle, int willCompleteOnCycle)
{
    std::cout << "Creating Mission" << std::endl;
    Mission *x = new Mission();
    x->setName(_name);
    x->setStartedOnCycle(startCycle);
    x->setWillCompleteOnCycle(willCompleteOnCycle);
    return x;
}

Mission* MissionFactory::createMissionFromResource()
{
    return create(1);
}
