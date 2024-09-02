#ifndef SRC_PLANET_FACTORY_H_
#define SRC_PLANET_FACTORY_H_

#include "planet.h"

class PlanetFactory {
 public:
    PlanetFactory();
    
    Planet* create();
    Planet* create(int i);
    Planet createPlanetFromResource();
  
 protected:
 private:
    
    
};

#endif