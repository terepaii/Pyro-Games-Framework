#include <Concrete\NormalDraw.h>

NormalDraw::NormalDraw()
{
}

NormalDraw::~NormalDraw()
{
}

/**
 * Draw a square to the RenderTarget
 */
void NormalDraw::drawSquare(sf::RenderTarget& target, const sf::Vector2f& pos,int size, const sf::Color& color)
{
	sf::RectangleShape rect(sf::Vector2f((float)size, (float)size));
	rect.setPosition(pos);
	rect.setFillColor(color);
	target.draw(rect);
}