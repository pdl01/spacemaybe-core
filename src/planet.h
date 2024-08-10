#ifndef SRC_PLANET_H_
#define SRC_PLANET_H_

#include <string>
#include <vector> 

#include "populationsection.h"

class Planet {
 public:
    Planet();
    
    void executeCycle();
    void setName(std::string _name);
    std::string getName();

   void addPopulationSection (PopulationSection* populationSection);

 protected:
 private:
    std::string name;
    int size;
    int cluster;
    
    std::vector<PopulationSection*> populationSections;

};

#endif