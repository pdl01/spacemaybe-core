#include "coordinate.h"
#include <iostream>
#include <cmath>

Coordinate::Coordinate()
{

    std::cout << "Constructing Coordinate" << std::endl;

}

Coordinate::Coordinate(int _x, int _y, int _z,std::string _coordinateSet)
{

    std::cout << "Constructing Coordinate" << std::endl;
    x = _x;
    y = _y;
    z = _z;
    coordinateSet = _coordinateSet;

}
float Coordinate::findDistanceBetween(Coordinate _y) {
    //sqrt[(this.x - _y.x)^2 + (this.y - _y.y)^2 + (this.z - _y.z)^2]
    int aaa = pow ((x-_y.x),2) + pow ((y-_y.y),2) + pow ((z - _y.z),2);
    float distance = sqrt(aaa);
    

    return distance;
}

int Coordinate::getX() {
    return this->x;
}
int Coordinate::getY() {
    return this->y;
}
int Coordinate::getZ() {
    return this->z;
}



