#include "Concrete\AggressiveState.h"

#include "Concrete\PassiveState.h"
#include "Concrete\Enemy.h"

AggressiveState::AggressiveState()
    : isGoingLeft(true)
{

}

AggressiveState::~AggressiveState()
{
    
}

void AggressiveState::onSet(Enemy& enemy)
{
    enemy.setColor(sf::Color::Yellow);
}

void AggressiveState::handle(Enemy& enemy)
{
    enemy.moveDown();

    if(clock.getElapsedTime() > sf::milliseconds(500))
    {
        isGoingLeft = !isGoingLeft;
        clock.restart();
    }

    if(isGoingLeft)
    {
        enemy.moveLeft();
    }
    else
    {
        enemy.moveRight();
    }
}