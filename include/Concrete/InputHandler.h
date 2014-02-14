#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <string>
#include <map>
#include <memory>
#include <SFML\Window\Event.hpp>
#include <SFML\Window\Keyboard.hpp>
#include <SFML\Window\Window.hpp>

#include "Interfaces\ICommand.h"

/**
* Processes window events and will execute commands based on these events.
* Events are mapped to commands and stored in here.
*/
class InputHandler
{
public:
    InputHandler();
    virtual ~InputHandler();

    /**
    * Handles the input event and executes the mapped command if applicable
    */
    void handleEvent(sf::Window &window, const sf::Event& sysEvent);

    /* Get the real time keyboard and mouse state and execute any commands
    * that are mapped to currently pressed keys and buttons
    */
    void update();

    /**
    * Binds a key press to a command. The command will be execute on key press
    */
    void setBind(const sf::Keyboard::Key key, const std::shared_ptr<ICommand>& command);

    /**
    * Binds a mouse click to a command. The command will be execute on click
    */
    void setBind(const sf::Mouse::Button button, const std::shared_ptr<ICommand>& command);

    /**
    * Removes a key bind. No command will be executed from the key press until set again
    */
    void removeBind(const sf::Keyboard::Key key);

    /**
    * Removes a mouse bind. No command will be executed from the mouse click until set again
    */
    void removeBind(const sf::Mouse::Button button);

    /**
    * Removes all key binds
    */
    void removeAllKeyBinds();
    
    /**
    * Removes all mouse binds
    */
    void removeAllMouseBinds();

    /**
    * Removes all key and mouse binds
    */
    void removeAllBinds();

private:
    typedef std::map<const sf::Keyboard::Key, std::shared_ptr<ICommand>> KeyBinder;
    typedef std::map<const sf::Mouse::Button, std::shared_ptr<ICommand>> MouseBinder;

    KeyBinder keyBinds;
    MouseBinder mouseBinds;
};

#endif //INPUTHANDLER_H