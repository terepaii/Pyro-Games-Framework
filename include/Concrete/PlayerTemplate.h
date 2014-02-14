#ifndef PLAYERTEMPLATE_H_
#define PLAYERTEMPLATE_H_

#include "Interfaces\IEntityTemplate.h"
#include "Concrete\Player.h"
#include "Concrete\PolygonDraw.h"

/**
* Defines an entity template for a player
*/
class PlayerTemplate : public IEntityTemplate
{
public:
    /**
    * Creates a player
    */
    virtual IEntity* createEntity();
};

#endif //PLAYERTEMPLATE_H_