#ifndef ENEMY_H
#define ENEMY_H

#include "Interfaces\IEntity.h"
#include "Interfaces\IEnemyState.h"

/**
 * Concrete Entity that uses the state pattern for handling AI logic
 */
class Enemy : public IEntity
{
public:
    Enemy();
    virtual ~Enemy();

     /**
    * Updates the enemy which includes updating the enemy state
    */
    virtual void update();

    /**
    * Sets the state of the enemy. This is typicall called from within the 
    * concrete states themselves, apart from setting the initial state
    */
    void setState(IEnemyState* state);

private:
    IEnemyState* state;
};
#endif // ENEMY_H
