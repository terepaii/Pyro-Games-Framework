#include <Concrete\EntityFactory.h>

RegisterEntityTemplateHelper::RegisterEntityTemplateHelper(std::string name, std::function<IEntityTemplate* (void)> entityTemplate)
{
    EntityFactory::instance().registerEntityTemplate(name, entityTemplate);
}

EntityFactory::EntityFactory()
{

}

EntityFactory::~EntityFactory()
{

}

EntityFactory& EntityFactory::instance()
{
    static EntityFactory factory;
    return factory;
}

void EntityFactory::registerEntityTemplate(std::string name, std::function<IEntityTemplate*(void)> entityTemplate)
{
    entityTemplates[name] = entityTemplate;
}

IEntity* EntityFactory::create(std::string name)
{
    return entityTemplates.find(name) != entityTemplates.end() ? entityTemplates[name]()->createEntity() : nullptr;
}