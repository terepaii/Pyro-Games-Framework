#include "Concrete\CollisionHandler.h"


CollisionHandler::CollisionHandler()
    : totalCollisions(0)
{
    
}

CollisionHandler::~CollisionHandler()
{
}

void CollisionHandler::onCollision(IEntity* entityA, IEntity* entityB)
{
    handleProjectileEnemyCollision(dynamic_cast<Projectile*>(entityA), dynamic_cast<Enemy*>(entityB));
    handleProjectileEnemyCollision(dynamic_cast<Projectile*>(entityB), dynamic_cast<Enemy*>(entityA));
}

void CollisionHandler::handleProjectileEnemyCollision(Projectile* p, Enemy* e)
{
    if(p != NULL && e != NULL)
    {
        p->kill();
        e->kill();
        totalCollisions++;
        notifyObservers();
    }
}

const int CollisionHandler::getTotalCollisions() const
{
    return totalCollisions;
}