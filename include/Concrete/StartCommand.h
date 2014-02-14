#ifndef STARTCOMMAND_H
#define STARTCOMMAND_H

#include "Interfaces\ICommand.h"
#include "Concrete\Squaliens.h"
#include "Concrete\InGameState.h"

/**
* 
*/
class StartCommand : public ICommand
{
public:
    StartCommand(Squaliens& game);
    virtual ~StartCommand();

    virtual void execute();

private:
    Squaliens& game;
};

#endif //STARTCOMMAND_H