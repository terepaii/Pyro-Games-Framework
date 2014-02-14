#include "Concrete\StartScreen.h"

StartScreen::StartScreen()
{

}

StartScreen::~StartScreen()
{

}

void StartScreen::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(text);
}

void StartScreen::setStartText(sf::Text& text)
{
    this->text = text;
}