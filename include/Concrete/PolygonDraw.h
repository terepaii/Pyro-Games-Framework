#ifndef POLYGONDRAW_H
#define POLYGONDRAW_H

#include "SFML\Graphics\ConvexShape.hpp"

#include "Interfaces\IRenderer.h"

/**
 * Concrete renderer using the bridge pattern. One way of drawing
 */
class PolygonDraw : public IRenderer
{
public:
	PolygonDraw();
	virtual ~PolygonDraw();
	virtual void drawSquare(sf::RenderTarget& target, const sf::Vector2f& pos,int size, const sf::Color& color);
};

#endif // POLYGONDRAW_H