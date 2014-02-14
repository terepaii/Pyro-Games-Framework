#include "Concrete\MoveEntityRightCommand.h"

MoveEntityRightCommand::MoveEntityRightCommand(sf::Window& window, IEntity& entity)
    : window(window), entity(entity)
{
}

MoveEntityRightCommand::~MoveEntityRightCommand()
{
}

void MoveEntityRightCommand::execute()
{
    if(entity.getPos().x + entity.getSize() < window.getSize().x)
    {
        entity.moveRight();
    }
}