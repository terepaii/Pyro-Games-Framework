#ifndef SHOOTCOMMAND_H
#define SHOOTCOMMAND_H

#include "SFML\System\Clock.hpp"

#include "Interfaces\IEntity.h"
#include "Interfaces\ICommand.h"
#include "Concrete\World.h"
#include "Concrete\EntityFactory.h"

/**
* Concrete command that creates projectiles relative to an entity's position.
*/
class ShootCommand : public ICommand
{
public:
    ShootCommand(World& world, IEntity& entity, sf::Time delay);
    virtual ~ShootCommand();

    virtual void execute();

private:
    World& world;
    IEntity& entity;

    sf::Time delay;
    sf::Clock clock;
};

#endif //SHOOTCOMMAND_H