#ifndef NORMALDRAW_H
#define NORMALDRAW_H

#include "SFML\Graphics\RectangleShape.hpp"

#include "Interfaces\IRenderer.h"

/**
 * Concrete renderer using the bridge pattern. One way of drawing
 */
class NormalDraw : public IRenderer
{
public:
	NormalDraw();
	virtual ~NormalDraw();
	virtual void drawSquare(sf::RenderTarget& target, const sf::Vector2f& pos,int size, const sf::Color& color);
};

#endif // NORMALDRAW_H