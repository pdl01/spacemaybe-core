#ifndef SRC_POPULATIONGROUP_FACTORY_H_
#define SRC_POPULATIONGROUP_FACTORY_H_

#include "populationgroup.h"
#include "attributefactory.h"
#include "technologyfactory.h"
#include "missionfactory.h"


class PopulationGroupFactory {
 public:
   PopulationGroupFactory();
    
    PopulationGroup* create();
    PopulationGroup* create(int i);
    PopulationGroup* createPopulationGroupFromResource();
  
 protected:
 private:
    
    TechnologyFactory technologyFactory;
    AttributeFactory attributeFactory;
};

#endif