#ifndef RENDERERFACTORY_H
#define RENDERERFACTORY_H

#include <map>

#include "SFML\System\NonCopyable.hpp"

#include "Interfaces\IRenderer.h"
#include "Concrete\PolygonDraw.h"
#include "Concrete\NormalDraw.h"


/**
* Enum to use as keys for flyweight factory
*/
enum DrawingAPI
{
    NORMAL,
    POLYGON
};

/**
* A flyweight factory for managing renderers. One renderer can be shared as all
* the information needed to render an item is provided from an external source
* Using renderers as flyweights saves memory
*/
class RendererFactory : sf::NonCopyable
{
public:
    virtual ~RendererFactory();

    /**
     * Return a singleton instance of this factory 
     */
    static RendererFactory& instance();

    /**
    * Gets the flyweight renderer. If it doesn't already exist, then it
    * will create a new one before returning it
    */
    IRenderer* getRenderer(DrawingAPI key);

private:
    /**
    * Constructor is only visible to this class and subclasses
    */
    RendererFactory();

    std::map<DrawingAPI, IRenderer*> renderers;
};

#endif //RENDERERFACTORY_H