#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Interfaces\IEntity.h"

/**
 * Concrete entity that defines a projectile
 */
class Projectile : public IEntity
{
public:
    Projectile();
    virtual ~Projectile();

    virtual void update();
};

#endif // PROJECTILE_H