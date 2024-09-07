#ifndef SRC_POPULATION_GROUP_H_
#define SRC_POPULATION_GROUP_H_
#include <vector> 
#include <map>
#include <string>
#include "technology.h"
#include "attribute.h"
#include "mission.h"

class PopulationGroup {
 public:
    PopulationGroup();
    void setName(std::string _name);
    std::string getName();
    
    void addTechnology(Technology* technology);
    void addAttribute(Attribute* attribute);

    std::vector<Technology*> getTechnologies();
    std::map<std::string,Attribute> getAttributes();
    
    void setAge(int _name);
    int getAge();
    void incrementAge();

 protected:
 private:
    std::string name;
    int turnEstablished;
    int age;

    std::vector<Technology*> technologies;
    std::map<std::string,Attribute> attributes;
    std::vector<Mission*> activeMissions;
    
};

#endif