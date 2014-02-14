#ifndef SMALLENEMYTEMPLATE_H_
#define SMALLENEMYTEMPLATE_H_

#include "Interfaces\IEntityTemplate.h"
#include "Concrete\Enemy.h"
#include "PassiveState.h"
#include "Concrete\PolygonDraw.h"

/**
* Defines an entity template for a small that is a bit faster than a large enemy
*/
class SmallEnemyTemplate : public IEntityTemplate
{
public:
    /**
    * Creates a small enemy
    */
    virtual IEntity* createEntity();
};

#endif //SMALLENEMYTEMPLATE_H_