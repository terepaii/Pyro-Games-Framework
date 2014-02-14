#ifndef PROJECTILETEMPLATE_H_
#define PROJECTILETEMPLATE_H_

#include "Interfaces\IEntityTemplate.h"
#include "Concrete\Projectile.h"
#include "Concrete\PolygonDraw.h"

/**
* Defines a template for a small enemy
*/
class ProjectileTemplate : public IEntityTemplate
{
public:
    /**
    * Creates a small enemy
    */
    virtual IEntity* createEntity();
};

#endif //PROJECTILETEMPLATE_H_