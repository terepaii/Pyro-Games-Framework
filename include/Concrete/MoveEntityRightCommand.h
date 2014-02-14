#ifndef MOVEENTITYRIGHTCOMMAND_H
#define MOVEENTITYRIGHTCOMMAND_H

#include "SFML\Window\Window.hpp"

#include "Interfaces\IEntity.h"
#include "Interfaces\ICommand.h"

/**
* Concrete command that executes the move right function defined in the 
* IEntity interface as long as it doesn't result the entity going outside of the window
*/
class MoveEntityRightCommand : public ICommand
{
public:
    MoveEntityRightCommand(sf::Window& window, IEntity& entity);
    virtual ~MoveEntityRightCommand();

    virtual void execute();

private:
    sf::Window& window;
    IEntity& entity;
};

#endif //MOVEENTITYRIGHTCOMMAND_H