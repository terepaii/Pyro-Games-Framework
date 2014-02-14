#ifndef WORLD_H
#define WORLD_H

#include <vector>

#include "SFML\Graphics\Drawable.hpp"
#include "Concrete\Player.h"
#include "Concrete\CollisionHandler.h"

/**
* Defines an entity world for management. It holds all the active entities.
* It updates, draws, and checks collisions between them
*/
class World : public sf::Drawable
{
public:
    World();
    virtual ~World();

    void addEntity(IEntity& entity);
    void removeEntity(IEntity& entity);

    void setPlayer(Player& player);
    Player* getPlayer();

    void update();
    
    void checkCollisions();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    CollisionHandler& getCollisionHandler();

private:
    std::vector<IEntity*> entities;
    CollisionHandler collisionHandler;
    Player* player;
};

#endif //WORLD_H