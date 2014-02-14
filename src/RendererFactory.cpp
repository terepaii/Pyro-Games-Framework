#include "Concrete\RendererFactory.h"

RendererFactory::RendererFactory()
{

}

RendererFactory::~RendererFactory()
{

}

RendererFactory& RendererFactory::instance()
{
    static RendererFactory factory;
    return factory;
}

IRenderer* RendererFactory::getRenderer(DrawingAPI key)
{
    std::map<DrawingAPI, IRenderer*>::iterator it = renderers.find(key);
    if(it != renderers.end())
    {
        return it->second;
    }

    IRenderer* renderer = nullptr;
    switch(key)
    {
    case DrawingAPI::NORMAL:
        renderer = new NormalDraw();
        renderers[key] = renderer;
        break;
    case DrawingAPI::POLYGON:
        renderer = new NormalDraw();
        renderers[key] = renderer;
        break;
    default:
        break;
    }

    return renderer;
}