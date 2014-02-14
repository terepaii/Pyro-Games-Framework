#include <Concrete\Squaliens.h>

Squaliens::Squaliens()
    : window(sf::VideoMode(600, 800), "Render Test", sf::Style::Default, sf::ContextSettings(32))
{
    srand((unsigned int)std::time(NULL));
    window.setFramerateLimit(30);
    gameFont.loadFromFile("resources\\arial.ttf");
    worldCeiling = -100;
    spawnDelay = sf::seconds(1.0f);
    state = nullptr;
}

Squaliens::~Squaliens()
{

}

void Squaliens::run()
{
    setState(new StartScreenState());

    /*loadStartScreen();
    loadHUD();
    IEntity* player = loadPlayer();
    loadInputConfig(*player);*/


    while(window.isOpen())
    {
        sf::Event sysEvent;
        while(window.pollEvent(sysEvent))
        {
            input.handleEvent(window, sysEvent);
        }

        update();

        draw();
    }
}

void Squaliens::update()
{
    if(state)
    {
        state->update(*this);
    }
}

void Squaliens::draw()
{
    if(state)
    {
        state->draw(*this);
    }
}

void Squaliens::setState(ISqualiensState* state)
{
    delete this->state;
    this->state = state;
    if(state)
    {
        state->onSet(*this);
    }
}

IEntity* Squaliens::loadPlayer()
{
    auto instance = EntityFactory::instance().create("Player");
    Player* player = dynamic_cast<Player*>(instance);

    int half = player->getSize() / 2;
    unsigned int windowWidth = window.getSize().x;
    unsigned int windowHeight = window.getSize().y;
    player->setPos( sf::Vector2f( (float)windowWidth / 2 - half, (float)windowHeight - (half * 3) ) );

    world.addEntity(*player);
    world.setPlayer(*player);
    return player;
}

sf::Vector2f Squaliens::generatePos()
{
    int xrand = Utils::generateRand(50, window.getSize().x - 100);
    return sf::Vector2f((float)xrand, (float)worldCeiling);
}

IEntity* Squaliens::loadLargeEnemy()
{
    auto instance = EntityFactory::instance().create("LargeEnemy");
    instance->setPos(generatePos());
    world.addEntity(*instance);
    return instance;
}

IEntity* Squaliens::loadSmallEnemy()
{
    auto instance = EntityFactory::instance().create("SmallEnemy");
    instance->setPos(generatePos());
    world.addEntity(*instance);
    return instance;
}

void Squaliens::spawnEnemies()
{
    if(spawnClock.getElapsedTime() > spawnDelay)
    {
        if(Utils::generateRand(0, 100) > 25)
        {
            loadLargeEnemy();
        }
        else
        {
            loadSmallEnemy();
        }
        spawnClock.restart();
    }
}

void Squaliens::loadStartScreen()
{
    sf::Text text("Press Space to start", gameFont);
    sf::FloatRect bounds = text.getGlobalBounds();
    text.setPosition(window.getSize().x / 2 - (bounds.width / 2), window.getSize().y / 2 - (bounds.height / 2));
    startScreen.setStartText(text);
}

void Squaliens::loadHUD()
{ 
    sf::Text text("There have been 0 collisions", gameFont);
    hud.setCollisionInfoText(text);
    world.getCollisionHandler().attachObserver(&hud);
}

sf::RenderWindow& Squaliens::getWindow()
{
    return window; 
}

HeadsUpDisplay& Squaliens::getHUD()
{
    return hud;
}

StartScreen& Squaliens::getStartScreen()
{
    return startScreen;
}

InputHandler& Squaliens::getInputHandler()
{
    return input;
}

World& Squaliens::getWorld()
{
    return world;
}
