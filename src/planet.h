#ifndef SRC_PLANET_H_
#define SRC_PLANET_H_

#include <string>
#include <vector> 

#include "coordinate.h"

class Planet {
 public:
    Planet();
    
    void executeCycle();
    void setName(std::string _name);
    std::string getName();


    void setUniverseCoordinate(Coordinate _coordinate);
    Coordinate getUniverseCoordinate();

 protected:
 private:
    std::string name;
    int size;
    int cluster;
    Coordinate universeCoordinate;

};

#endif