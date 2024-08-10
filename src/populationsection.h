#ifndef SRC_POPULATION_SECTION_H_
#define SRC_POPULATION_SECTION_H_
#include <vector> 
#include <string>
#include "technology.h"
#include "attribute.h"

class PopulationSection {
 public:
    PopulationSection();
    void setName(std::string _name);
    std::string getName();
    
    void addTechnology(Technology* technology);
    void addAttribute(Attribute* attribute);

    std::vector<Technology*> getTechnologies();
    std::vector<Attribute*> getAttributes();

 protected:
 private:
    std::string name;
    int turnEstablished;

    std::vector<Technology*> technologies;
    std::vector<Attribute*> attributes;
    
    
};

#endif