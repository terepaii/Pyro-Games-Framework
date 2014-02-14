#include "Concrete\StartScreenState.h"
#include "Concrete\Squaliens.h"

#include "Concrete\StartCommand.h"

StartScreenState::StartScreenState()
{

}

StartScreenState::~StartScreenState()
{

}

void StartScreenState::onSet(Squaliens& game)
{
    game.loadStartScreen();

    InputHandler& input = game.getInputHandler();
    input.removeAllBinds();
    input.setBind(sf::Keyboard::Space, std::shared_ptr<StartCommand>(new StartCommand(game)));
}

void StartScreenState::update(Squaliens& game)
{
    game.getInputHandler().update();
}

void StartScreenState::draw(Squaliens& game)
{
    sf::RenderWindow& window = game.getWindow();

    window.clear(sf::Color::Black);
    window.draw(game.getStartScreen());
    window.display();
}