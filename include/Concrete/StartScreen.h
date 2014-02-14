#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include "SFML\Graphics\Drawable.hpp"
#include "SFML\Graphics\Text.hpp"
#include "SFML\Graphics\RenderTarget.hpp"

/**
* Start screen that is displayed before the game starts
*/
class StartScreen : public sf::Drawable
{
public:
    StartScreen();
    virtual ~StartScreen();

    /**
    * Draws the start screen
    */
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    /**
    * Sets the font that is used
    */
    void setStartText(sf::Text& text);

private:
    sf::Text text;
};

#endif //HEADSUPDISPLAY_H