#ifndef SQUALIENS_H
#define SQUALIENS_H

#include "SFML\Graphics\RenderWindow.hpp"

#include "Utils.h"
#include "Interfaces\IGame.h"
#include "Interfaces\ISqualiensState.h"
#include "Concrete\StartScreenState.h"

#include "Concrete\World.h"
#include "Concrete\HeadsUpDisplay.h"
#include "Concrete\EntityFactory.h"
#include "Concrete\StartScreen.h"

#include "Concrete\InputHandler.h"

/**
* Concrete game. This is the top layer that controls the entire program
*/
class Squaliens : public IGame
{
public:
    Squaliens();
    ~Squaliens();

    /**
    * Kicks off the program and contains the game loop
    */
    virtual void run();

    /**
    * Sets the state of the game
    */
    void setState(ISqualiensState* state);

    /**
    * Loads a player and adds it to the world
    */
    IEntity* loadPlayer();

    /**
    * Randomly generates a position based on the criteria
    */
    sf::Vector2f generatePos();

    /**
    * Loads an enemy using the LargeEnemy template
    */
    IEntity* loadLargeEnemy();

    /**
    * Loads an enemy using the SmallEnemy template
    */
    IEntity* loadSmallEnemy();

    /**
    * Loads the start screen
    */
    void loadStartScreen();

    /**
    * Loads the HUD elements
    */
    void loadHUD();

    /**
    * Spawns Enemies randomly abiding to the spawn delay
    */
    void spawnEnemies();

    //Getters for the state
    sf::RenderWindow& getWindow();
    HeadsUpDisplay& getHUD();
    StartScreen& getStartScreen();
    InputHandler& getInputHandler();
    World& getWorld();

protected:
    /**
    * Updates the world and input
    */
    virtual void update();

    /**
    * Renders the game to the screen
    */
    virtual void draw();

private:
    ISqualiensState* state;
    World world;
    sf::RenderWindow window;

    HeadsUpDisplay hud;
    StartScreen startScreen;

    sf::Font gameFont;
    InputHandler input;

    sf::Clock spawnClock;
    sf::Time spawnDelay;
    int worldCeiling;
};

#endif // SQUALIENS_H