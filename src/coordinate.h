#ifndef SRC_COORDINATE_H_
#define SRC_COORDINATE_H_
#include <string>

class Coordinate {
 public:
    Coordinate();
    Coordinate(int x, int y, int z,std::string coordinateSet);
    float findDistanceBetween(Coordinate y);
    int getX();
    int getY();
    int getZ();

    
 protected:
 private:
    int x;
    int y;
    int z;
    std::string coordinateSet;
};

#endif