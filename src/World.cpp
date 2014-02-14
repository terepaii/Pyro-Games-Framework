#include "Concrete\World.h"

World::World()
{
    
}

World::~World()
{
    for(unsigned int i = 0; i < entities.size(); i++)
    {
        delete entities.at(i);
    }
}

void World::addEntity(IEntity& entity)
{
    entities.push_back(&entity);
}

void World::removeEntity(IEntity& entity)
{
    for(unsigned int i = 0; i < entities.size(); i++)
    {
        if(entities.at(i) == &entity)
        {
            entities.erase(entities.begin() + i);
            return;
        }
    }
}

void World::setPlayer(Player& player)
{
    this->player = &player;
}

Player* World::getPlayer()
{
    return player;
}

void World::update()
{
    IEntity* entity;
    for(unsigned int i = 0; i < entities.size(); i++)
    {
        entity = entities.at(i);
        if(entity->isDead())
        {
            delete entity;
            entities.erase(entities.begin() + i);
            i--;
        }
        else
        {
            entity->update();
        }
    }

    checkCollisions();
}

void World::checkCollisions()
{
    IEntity* e1, *e2;
    for(unsigned int i = 0; i < entities.size(); i++)
    {
        e1 = entities.at(i);
        for(unsigned int j = i+1; j < entities.size(); j++)
        {
            e2 = entities.at(j);
            if(e1->getCollisionBox().intersects(e2->getCollisionBox()))
            {
                collisionHandler.onCollision(e1, e2);
            }
        }
    }
}

void World::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for(unsigned int i = 0; i < entities.size(); i++)
    {
        target.draw(*entities.at(i));
    }
}

CollisionHandler& World::getCollisionHandler()
{
    return collisionHandler;
}