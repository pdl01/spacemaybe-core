#ifndef SRC_ATTRIBUTE_FACTORY_H_
#define SRC_ATTRIBUTE_FACTORY_H_

#include "attribute.h"

class AttributeFactory {
 public:
    AttributeFactory();
    
    Attribute* create();
    Attribute* create(int i);
    Attribute createAttributeFromResource();
  
 protected:
 private:
    
    
    
};

#endif