#include "Concrete\PlayerTemplate.h"

#include "Concrete\EntityFactory.h"
REGISTER_ENTITY_TEMPLATE("Player", PlayerTemplate);

#include "Concrete\RendererFactory.h"

IEntity* PlayerTemplate::createEntity()
{
    Player* p = new Player();
    p->setPos(sf::Vector2f(50, 50));
    p->setColor(sf::Color::Red);
    p->setRenderer(*RendererFactory::instance().getRenderer(DrawingAPI::POLYGON));
    p->setSize(70);
    p->setVelocity(sf::Vector2f(15, 15));
    return p;
}