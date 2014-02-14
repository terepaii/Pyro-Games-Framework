#ifndef PASSIVE_STATE_H
#define PASSIVE_STATE_H

#include "SFML\System\Clock.hpp"

#include "Interfaces\IEnemyState.h"

/**
* Concrete enemy state that makes the enemy passive for a limited time, then changes state
*/
class PassiveState: public IEnemyState
{
public:
    PassiveState();
    ~PassiveState();

    virtual void handle(Enemy& enemy);

private:
    sf::Clock clock;
};

#endif // PASSIVE_STATE_H