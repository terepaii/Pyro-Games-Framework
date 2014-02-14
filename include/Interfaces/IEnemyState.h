#ifndef IENEMYSTATE_H
#define IENEMYSTATE_H

class Enemy;

/**
* State interface for the AI of an enemy.
*/
class IEnemyState
{
public:
    IEnemyState() {}
    ~IEnemyState() {}

    /**
    * An init function that should be called when setting the state of the enemy.
    * This is for any intialization logic but is seperate from the constructor
    * incase states are created before hand without being immediately set
    */
    virtual void onSet(Enemy& enemy) {}

    /**
    * pure virtual function that is used to handle state operations on the enemy
    */
    virtual void handle(Enemy& enemy) = 0;
};

#endif // IENEMYSTATE_H 