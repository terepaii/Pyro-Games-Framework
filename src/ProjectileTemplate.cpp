#include "Concrete\ProjectileTemplate.h"

#include "Concrete\EntityFactory.h"
REGISTER_ENTITY_TEMPLATE("Projectile", ProjectileTemplate);

IEntity* ProjectileTemplate::createEntity()
{
    Projectile* p = new Projectile();
    p->setPos(sf::Vector2f(0, 0));
    p->setColor(sf::Color::White);
    p->setRenderer(*new PolygonDraw());
    p->setSize(5);
    p->setVelocity(sf::Vector2f(20, 20));
    return p;
}