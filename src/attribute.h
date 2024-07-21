#ifndef SRC_ATTRIBUTE_H_
#define SRC_ATTRIBUTE_H_
#include <string>

class Attribute {
 public:
    Attribute();
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