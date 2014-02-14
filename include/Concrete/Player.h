#ifndef PLAYER_H
#define PLAYER_H

#include <Interfaces\IEntity.h>

/**
 * Concrete entity that defines the player
 */
class Player : public IEntity
{
public:
    Player();
    virtual ~Player();

    virtual void update();
};

#endif // PLAYER_H