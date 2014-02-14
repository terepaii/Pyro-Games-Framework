#ifndef HEADSUPDISPLAY_H
#define HEADSUPDISPLAY_H

#include "SFML\Graphics\Drawable.hpp"
#include "SFML\Graphics\Font.hpp"
#include "SFML\Graphics\Text.hpp"

#include "Interfaces\IObserver.h"
#include "Concrete\CollisionHandler.h"
#include "Utils.h"

/**
* A concrete observer. This displays information to the player as part of the UI
*/
class HeadsUpDisplay : public IObserver, public sf::Drawable
{
public:
    HeadsUpDisplay();
    virtual ~HeadsUpDisplay();

    /**
    * sets the HUD components to the updated subject values
    */
    virtual void update(const Subject* subject);

    /**
    * Draws all the HUD components to the screen
    */
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;


    void setCollisionInfoText(sf::Text& text);

private:
    sf::Text collisionInfoText;
};

#endif //HEADSUPDISPLAY_H