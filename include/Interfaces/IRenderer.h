#ifndef IRENDERER_H
#define IRENDERER_H

#include "SFML\Graphics\RenderTarget.hpp"

/**
 * Abstract class for rendering objects. This provides a bridge between the
 * renderable object and the rendering logic
 */
class IRenderer
{
public:
    virtual ~IRenderer() {}

    virtual void drawSquare(sf::RenderTarget& target, const sf::Vector2f& pos, int size, const sf::Color& color) = 0;

protected:
    IRenderer() {};
};

#endif // IRENDERER_H