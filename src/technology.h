#ifndef SRC_TECHNOLOGY_H_
#define SRC_TECHNOLOGY_H_
#include <string>

class Technology {
 public:
    Technology();
    void setName(std::string _name);
    std::string getName();
    void setLevel(int level);
    int getLevel();

   
 protected:
 private:
    std::string name;
    int level;
};

#endif