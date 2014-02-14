#include "Concrete\Subject.h"

Subject::Subject()
{

}

Subject::~Subject()
{

}

void Subject::attachObserver(IObserver* observer)
{
    if(observer != NULL)
    {
        observers.insert(observer);
    }
}

void Subject::detachObserver(IObserver* observer)
{
    if(observer != NULL)
    {
        std::set<IObserver*>::iterator it = observers.find(observer);
        if(it != observers.end())
        {
            observers.erase(it);
        }
    }
}

void Subject::notifyObservers()
{
    std::set<IObserver*>::iterator it;
    for(it = observers.begin(); it != observers.end(); it++)
    {
        (*it)->update(this);
    }
}