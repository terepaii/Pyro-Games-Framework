#include "Concrete\MoveEntityLeftCommand.h"

MoveEntityLeftCommand::MoveEntityLeftCommand(sf::Window& window, IEntity& entity)
    : window(window), entity(entity)
{
}

MoveEntityLeftCommand::~MoveEntityLeftCommand()
{
}

void MoveEntityLeftCommand::execute()
{
    if(entity.getPos().x > 0)
    {
        entity.moveLeft();
    }
}