#include "Concrete\LargeEnemyTemplate.h"

#include "Concrete\EntityFactory.h"
REGISTER_ENTITY_TEMPLATE("LargeEnemy", LargeEnemyTemplate);

#include "Concrete\RendererFactory.h"

IEntity* LargeEnemyTemplate::createEntity()
{
    Enemy* e = new Enemy();
    e->setPos(sf::Vector2f(300, 100));
    e->setColor(sf::Color::Green);
    e->setRenderer(*RendererFactory::instance().getRenderer(DrawingAPI::POLYGON));
    e->setSize(100);
    e->setVelocity(sf::Vector2f(4, 4));
    e->setState(new PassiveState());
    return e;
}