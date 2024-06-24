#ifndef SRC_PLANET_H_
#define SRC_PLANET_H_

#include <string>

class Planet {
 public:
    Planet();
    
    void execute();
    void setName(char* _name);
    char* getName();

//    void setExit(bool _exit);
//    bool getExit();
    
//    void stop();
//void start();
//    
 protected:
 private:
    char* name;
    int size;
    int cluster;
    
    
};

#endif