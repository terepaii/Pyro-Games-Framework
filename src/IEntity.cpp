#include "Interfaces\IEntity.h"

IEntity::IEntity()
    : dead(false), size(1), color(sf::Color::White)
{

}

IEntity::~IEntity()
{

}

void IEntity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if(renderer)
    {
        renderer->drawSquare(target, pos, size, color);
    }
}

void IEntity::moveUp()
{
    pos.y -= getVelocity().y;
}

void IEntity::moveDown()
{
    pos.y += getVelocity().y;
}

void IEntity::moveLeft()
{
    pos.x -= getVelocity().x;
}

void IEntity::moveRight()
{
    pos.x += getVelocity().x;
}

void IEntity::setVelocity(sf::Vector2f& velocity)
{
    this->velocity = velocity;
}

const sf::Vector2f& IEntity::getVelocity() const
{
    return velocity;
}

void IEntity::setRenderer(IRenderer& renderer)
{
    this->renderer = &renderer;
}

void IEntity::setPos(sf::Vector2f& pos)
{
    this->pos = pos;
}

const sf::Vector2f& IEntity::getPos() const
{
    return pos;
}

void IEntity::setSize(int size) 
{ 
    this->size = size; 
}

const int IEntity::getSize() const 
{ 
    return size; 
}

void IEntity::setColor(sf::Color color) 
{ 
    this->color = color; 
}

const sf::Color& IEntity::getColor() const
{ 
    return color; 
}

void IEntity::kill()
{
    dead = true;
}

bool IEntity::isDead() const
{
    return dead;
}

const sf::FloatRect IEntity::getCollisionBox() const
{
    return sf::FloatRect(pos.x, pos.y, (float)size, (float)size);
}