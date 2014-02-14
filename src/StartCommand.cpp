#include "Concrete\StartCommand.h"

StartCommand::StartCommand(Squaliens& game)
    : game(game)
{

}

StartCommand::~StartCommand()
{

}

void StartCommand::execute()
{
    game.setState(new InGameState());
}