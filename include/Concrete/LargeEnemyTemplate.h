#ifndef LARGEENEMYTEMPLATE_H_
#define LARGEENEMYTEMPLATE_H_

#include "Interfaces\IEntityTemplate.h"
#include "Concrete\Enemy.h"
#include "PassiveState.h"

/**
* Concrete entity template. Defines a large and slightly slow enemy
*/
class LargeEnemyTemplate : public IEntityTemplate
{
public:
    /**
    * Creates a Large enemy
    */
    virtual IEntity* createEntity();
};

#endif //LARGEENEMYTEMPLATE_H_