#ifndef SRC_POPULATIONSECTION_FACTORY_H_
#define SRC_POPULATIONSECTION_FACTORY_H_

#include "populationsection.h"
#include "attributefactory.h"
#include "technologyfactory.h"

class PopulationSectionFactory {
 public:
    PopulationSectionFactory();
    
    PopulationSection* create();
    PopulationSection* create(int i);
    PopulationSection createPopulationSectionFromResource();
  
 protected:
 private:
    
    TechnologyFactory technologyFactory;
    AttributeFactory attributeFactory;
    
};

#endif