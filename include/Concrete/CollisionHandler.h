#ifndef COLLISIONHANDLER_H
#define COLLISIONHANDLER_H

#include "Concrete\Enemy.h"
#include "Concrete\Projectile.h"

#include "Concrete\Subject.h"

/**
* Handles collisions between entities. Collision data can be observed with observers
*/
class CollisionHandler : public Subject
{
public:
    CollisionHandler();
    virtual ~CollisionHandler();

    /**
    * Handles a collision between two entities
    */
    void onCollision(IEntity* entityA, IEntity* entityB);

    void handleProjectileEnemyCollision(Projectile* p, Enemy* e);

    const int getTotalCollisions() const;

private:
    int totalCollisions;
};

#endif //COLLISIONHANDLER_H