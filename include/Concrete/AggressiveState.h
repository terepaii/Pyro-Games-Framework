#ifndef AGGRESSIVE_STATE_H
#define AGGRESSIVE_STATE_H

#include "Interfaces\IEnemyState.h"

#include "SFML\System\Clock.hpp"

/**
* Concrete enemy state that makes the enemy more aggressive towards the player
*/
class AggressiveState: public IEnemyState
{
public:
    AggressiveState();
    ~AggressiveState();

    virtual void onSet(Enemy& enemy);

    virtual void handle(Enemy& enemy);

private:
    sf::Clock clock;
    bool isGoingLeft;
};

#endif // AGGRESSIVE_STATE_H