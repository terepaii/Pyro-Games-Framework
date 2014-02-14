#include "Concrete\HeadsUpDisplay.h"

HeadsUpDisplay::HeadsUpDisplay()
{

}

HeadsUpDisplay::~HeadsUpDisplay()
{

}

void HeadsUpDisplay::update(const Subject* subject)
{
    //only care if it's the collision handler
    if(const CollisionHandler* ch = dynamic_cast<const CollisionHandler*>(subject))
    {
        int total = ch->getTotalCollisions();
        std::string totalStr = Utils::numberToString<int>(total);
        std::string s = total == 1 ? "There has been 1 collision" : "There have been " + totalStr + " collisions";
        collisionInfoText.setString(s);
    }
}

void HeadsUpDisplay::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(collisionInfoText, states);
}

void HeadsUpDisplay::setCollisionInfoText(sf::Text& text)
{
    this->collisionInfoText = text;
}