#ifndef ICOMMAND_H
#define ICOMMAND_H

/**
* Command interface that encapsulates invokation.
*/
class ICommand
{
public:
    virtual ~ICommand() {}

    /**
    * Executes the command
    */
    virtual void execute() = 0;

protected:
    ICommand() {}
};

#endif //ICOMMAND_H