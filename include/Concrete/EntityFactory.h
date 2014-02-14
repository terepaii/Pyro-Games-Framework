#ifndef ENTITYFACTORY_H
#define ENTITYFACTORY_H

#include <memory>
#include <map>
#include <functional>
#include <string>

#include "SFML\System\NonCopyable.hpp"

#include "Interfaces\IEntityTemplate.h"

//Macro is used for concrete entity templates to automatically register themselves in their own source file
class RegisterEntityTemplateHelper;
#define REGISTER_ENTITY_TEMPLATE(NAME, TYPE) \
    static RegisterEntityTemplateHelper reg(NAME, [](void) -> IEntityTemplate* { return new TYPE(); });

/**
 * Helper class for registering classes with the factory
 */
class RegisterEntityTemplateHelper
{
public:
    /**
     * Constructor for the register helper class
     */
    RegisterEntityTemplateHelper(std::string name, std::function<IEntityTemplate*(void)> entityTemplate);
};

/**
 * Factory pattern used to create entities. It is a singleton. Entity templates
 * can be registered to the factory either at compile time or run time.
 * The templates are mapped to a name and are used to create and set inital values
 * of the entity
 */
class EntityFactory : sf::NonCopyable
{
public:
    virtual ~EntityFactory();

    /**
     * Return a singleton instance of this factory 
     */
    static EntityFactory& instance();

    /*
    * Registers a template class to the entity factory
    */
    void registerEntityTemplate(std::string name, std::function<IEntityTemplate*(void)> entityTemplate);

    /**
    * Creates an entity using the mapped entity template function
    */
    IEntity* create(std::string name);

private:
    /**
    * Constructor is only visible to this class and subclasses
    */
    EntityFactory();

    std::map<std::string, std::function<IEntityTemplate*(void)>> entityTemplates;
};

#endif //ENTITYFACTORY_H
