#include "Concrete\InputHandler.h"

InputHandler::InputHandler()
{
    
}

InputHandler::~InputHandler()
{

}

void InputHandler::handleEvent(sf::Window &window, const sf::Event& sysEvent)
{
    switch(sysEvent.type)
    {
        case sf::Event::Closed:
        {
            window.close();
            break;
        }
        default:
            break;
    }
}

void InputHandler::update()
{
    //We use temporary maps just incase any commands modify the binds upon execution.
    //Any modifications won't come into affect until the next update
    KeyBinder tempKeys(keyBinds.begin(), keyBinds.end());
    MouseBinder tempButtons(mouseBinds.begin(), mouseBinds.end());

    for(KeyBinder::iterator it = tempKeys.begin(); it != tempKeys.end(); it++)
    {
        sf::Keyboard::Key key = it->first;
        if(sf::Keyboard::isKeyPressed(key))
        {
            keyBinds[key]->execute();
        }
    }
    
    for(MouseBinder::iterator it = tempButtons.begin(); it != tempButtons.end(); it++)
    {
        sf::Mouse::Button button = it->first;
        if(sf::Mouse::isButtonPressed(button))
        {
            mouseBinds[button]->execute();
        }
    }
}

void InputHandler::setBind(const sf::Keyboard::Key key, const std::shared_ptr<ICommand>& command)
{
    keyBinds[key] = command;
}

void InputHandler::setBind(const sf::Mouse::Button button, const std::shared_ptr<ICommand>& command)
{
    mouseBinds[button] = command;
}

void InputHandler::removeBind(const sf::Keyboard::Key key)
{
    keyBinds.erase(key);
}

void InputHandler::removeBind(const sf::Mouse::Button button)
{
    mouseBinds.erase(button);
}

void InputHandler::removeAllKeyBinds()
{
    keyBinds.clear();
}

void InputHandler::removeAllMouseBinds()
{
    mouseBinds.clear();
}

void InputHandler::removeAllBinds()
{
    removeAllKeyBinds();
    removeAllMouseBinds();
}

