#include <Concrete\PolygonDraw.h>

PolygonDraw::PolygonDraw()
{
}

PolygonDraw::~PolygonDraw()
{
}

/**
 * Draw a square to the RenderTarget using an sf::ConvexShape
 */
void PolygonDraw::drawSquare(sf::RenderTarget& target, const sf::Vector2f& pos,int size, const sf::Color& color)
{
	
	sf::ConvexShape polygon(4U);
	
	polygon.setPosition(pos);

	sf::Vector2f firstp(0, 0);
	sf::Vector2f secondp(size, 0);
	sf::Vector2f thirdp(size, size);
	sf::Vector2f fourthp(0, size);

	polygon.setPoint(0, firstp);
	polygon.setPoint(1, secondp);
	polygon.setPoint(2, thirdp);
	polygon.setPoint(3, fourthp);

	polygon.setFillColor(color);

	target.draw(polygon);
}