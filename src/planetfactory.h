#ifndef SRC_PLANET_FACTORY_H_
#define SRC_PLANET_FACTORY_H_

#include "planet.h"
#include "planetarygeosection.h"

class PlanetFactory {
 public:
    PlanetFactory();
    
    Planet* create();
    Planet* create(int i);
    Planet* createPlanetFromResource();
    PlanetaryGeoSection* createPlanetaryGeoSection(int i);

 protected:
 private:
   int numOfGeoSections = 2000;
    
};

#endif