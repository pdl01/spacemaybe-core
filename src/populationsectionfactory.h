#ifndef SRC_POPULATIONSECTION_FACTORY_H_
#define SRC_POPULATIONSECTION_FACTORY_H_

#include "populationsection.h"

class PopulationSectionFactory {
 public:
    PopulationSectionFactory();
    
    PopulationSection* create();
    PopulationSection* create(int i);
    PopulationSection createPopulationSectionFromResource();
  
 protected:
 private:
    
    
    
};

#endif