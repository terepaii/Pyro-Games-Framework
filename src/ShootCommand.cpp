#include "Concrete\ShootCommand.h"

ShootCommand::ShootCommand(World& world, IEntity& entity, sf::Time delay)
    : world(world), entity(entity), delay(delay)
{
    
}

ShootCommand::~ShootCommand()
{
}

void ShootCommand::execute()
{
    if(clock.getElapsedTime() > delay)
    {
        IEntity* projectile = EntityFactory::instance().create("Projectile");
        int half = entity.getSize() / 2;
        sf::Vector2f spawnPos(entity.getPos().x + half, entity.getPos().y);
        projectile->setPos(spawnPos);
        world.addEntity(*projectile);
        clock.restart();
    }
}