#ifndef SRC_TECHNOLOGY_FACTORY_H_
#define SRC_TECHNOLOGY_FACTORY_H_

#include "technology.h"

class TechnologyFactory {
 public:
    TechnologyFactory();
    
    Technology* create();
    Technology* create(int i);
    //Technology createTechnologyFromResource();
  
 protected:
 private:
    
    
    
};

#endif