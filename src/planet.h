#ifndef SRC_PLANET_H_
#define SRC_PLANET_H_

#include <string>
#include <vector> 

#include "coordinate.h"
#include "planetarygeosection.h"

class Planet {
 public:
    Planet();
    
    void executeCycle();
    void setName(std::string _name);
    std::string getName();


    void setUniverseCoordinate(Coordinate _coordinate);
    Coordinate getUniverseCoordinate();

    void setGeoSections( std::vector<PlanetaryGeoSection*> _geoSections);
    std::vector<PlanetaryGeoSection*> getGeoSections();
    
 protected:
 private:
    std::string name;
    int size;
    int cluster;
    Coordinate universeCoordinate;
    std::vector<PlanetaryGeoSection*> geoSections;
};

#endif