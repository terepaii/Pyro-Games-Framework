#include "Concrete\PassiveState.h"

#include "Concrete\AggressiveState.h"
#include "Concrete\Enemy.h"

PassiveState::PassiveState()
{

}

PassiveState::~PassiveState()
{

}

void PassiveState::handle(Enemy& enemy)
{
    enemy.moveDown();
    if(clock.getElapsedTime() > sf::seconds(2.5f))
    {
        enemy.setState(new AggressiveState());
    }
}