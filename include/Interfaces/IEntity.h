#ifndef IENTITY_H
#define IENTITY_H

#include <string>

#include "SFML\Graphics\Drawable.hpp"


#include "Interfaces\IRenderer.h"


/**
 * Abstract base Entity class
 */
class IEntity : public sf::Drawable
{
public:
    virtual ~IEntity();

    /**
    * Updates the entity in the game loop. Implementation must be provided
    * in concrete entities 
    */
    virtual void update() = 0;

    /**
    * Draws the entity. We have an implementation in the interface to apply
    * the one rule one place principle for the bridge patternw
    */
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    virtual void moveUp();
    virtual void moveDown();
    virtual void moveLeft();
    virtual void moveRight();

    virtual void setVelocity(sf::Vector2f& velocity);
    virtual const sf::Vector2f& getVelocity() const;

    virtual void setRenderer(IRenderer& renderer);

    virtual void setPos(sf::Vector2f& pos);
    virtual const sf::Vector2f& getPos() const;

    virtual void setSize(int size);
    virtual const int getSize() const;

    virtual void setColor(sf::Color color);
    virtual const sf::Color& getColor() const;

    virtual void kill();
    virtual bool isDead() const;

    virtual const sf::FloatRect getCollisionBox() const;

protected:
    IEntity();

    IRenderer* renderer;
    sf::Vector2f pos;
    sf::Vector2f velocity;
    sf::Color color;
    int size;
    bool dead;
};

#endif // IENTITY_H