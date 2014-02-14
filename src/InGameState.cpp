#include "Concrete\InGameState.h"
#include "Concrete\Squaliens.h"

#include "Concrete\MoveEntityLeftCommand.h"
#include "Concrete\MoveEntityRightCommand.h"
#include "Concrete\ShootCommand.h"

InGameState::InGameState()
{

}

InGameState::~InGameState()
{

}

void InGameState::onSet(Squaliens& game)
{
    game.loadHUD();
    IEntity* player = game.loadPlayer();

    InputHandler& input = game.getInputHandler();
    input.removeAllBinds();
    input.setBind(sf::Keyboard::A, std::shared_ptr<MoveEntityLeftCommand>(new MoveEntityLeftCommand(game.getWindow(), *player)));
    input.setBind(sf::Keyboard::D, std::shared_ptr<MoveEntityRightCommand>(new MoveEntityRightCommand(game.getWindow(), *player)));
    input.setBind(sf::Mouse::Left, std::shared_ptr<ShootCommand>(new ShootCommand(game.getWorld(), *player, sf::milliseconds(250))));
}

void InGameState::update(Squaliens& game)
{
    game.spawnEnemies();
    game.getInputHandler().update();
    game.getWorld().update();
}

void InGameState::draw(Squaliens& game)
{
    sf::RenderWindow& window = game.getWindow();

    window.clear(sf::Color::Black);
    window.draw(game.getWorld());
    window.draw(game.getHUD());
    window.display();
}