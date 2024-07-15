#ifndef SRC_PLANET_H_
#define SRC_PLANET_H_

#include <string>

class Planet {
 public:
    Planet();
    
    void executeCycle();
    void setName(std::string _name);
    std::string getName();

//    void setExit(bool _exit);
//    bool getExit();
    
//    void stop();
//void start();
//    
 protected:
 private:
    std::string name;
    int size;
    int cluster;
    
    
};

#endif