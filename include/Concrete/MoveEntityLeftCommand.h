#ifndef MOVEENTITYLEFTCOMMAND_H
#define MOVEENTITYLEFTCOMMAND_H

#include "SFML\Window\Window.hpp"

#include "Interfaces\IEntity.h"
#include "Interfaces\ICommand.h"

/**
* Concrete command that executes the move left function defined in the 
* IEntity interface as long as it doesn't result the entity going outside of the window
*/
class MoveEntityLeftCommand : public ICommand
{
public:
    MoveEntityLeftCommand(sf::Window& window, IEntity& entity);
    virtual ~MoveEntityLeftCommand();

    virtual void execute();

private:
    sf::Window& window;
    IEntity& entity;
};

#endif //MOVEENTITYLEFTCOMMAND_H