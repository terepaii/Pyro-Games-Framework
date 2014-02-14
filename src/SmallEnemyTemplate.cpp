#include "Concrete\SmallEnemyTemplate.h"

#include "Concrete\EntityFactory.h"
REGISTER_ENTITY_TEMPLATE("SmallEnemy", SmallEnemyTemplate);

#include "Concrete\RendererFactory.h"

IEntity* SmallEnemyTemplate::createEntity()
{
    Enemy* e = new Enemy();
    e->setPos(sf::Vector2f(0, -200));
    e->setColor(sf::Color::Green);
    e->setRenderer(*RendererFactory::instance().getRenderer(DrawingAPI::POLYGON));
    e->setSize(50);
    e->setVelocity(sf::Vector2f(6, 6));
    e->setState(new PassiveState());
    return e;
}