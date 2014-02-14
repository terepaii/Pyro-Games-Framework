#ifndef IENTITYTEMPLATE_H_
#define IENTITYTEMPLATE_H_

#include "IEntity.h"

/**
* Interface for entity templates. Entity templates are used to create and
* set initial values to entity attributes and can be registered to the entity factory
*/
class IEntityTemplate
{
public:
    IEntityTemplate() {}
    virtual ~IEntityTemplate () {}

    /**
    * Creates the entity with initial values
    */
    virtual IEntity* createEntity() = 0;
};

#endif //IENTITYTEMPLATE_H_