#ifndef SRC_PLANETARYGEOSECTION_H_
#define SRC_PLANETARYGEOSECTION_H_

#include <string>
#include "populationgroup.h"

class PlanetaryGeoSection {
 public:
      PlanetaryGeoSection();
      PlanetaryGeoSection(int geoSectionId);
      PopulationGroup* getOwner();
      void setOwner(PopulationGroup* _owner);
      
 protected:
 private:
    PopulationGroup* owner;
    int geoSectionId;
    
};
#endif