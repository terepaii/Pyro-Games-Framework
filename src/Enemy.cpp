#include <Concrete\Enemy.h>

Enemy::Enemy() 
    : state(nullptr)
{ 
    
}
    
Enemy::~Enemy()
{
}

void Enemy::update()
{
    if(state)
    {
        state->handle(*this);
    }
}

void Enemy::setState(IEnemyState* state) 
{ 
    delete this->state; 
    this->state = state;
    if(state)
    {
        state->onSet(*this);
    }
}