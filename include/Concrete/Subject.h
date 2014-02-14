#ifndef SUBJECT_H
#define SUBJECT_H

#include <set>

#include "Interfaces\IObserver.h"

/**
* Defines a subject that can be observed by an observer. Although it's not
* an abstract class, it is intended only to be used as a super class, as the subject
* class has no observable data
*/
class Subject
{
public:
    virtual ~Subject();

   /**
    * Attaches an observer to the subject so they can subscribe to subject changes
    */
    virtual void attachObserver(IObserver* observer);

   /**
    * Detaches an observer from the subject
    */
    virtual void detachObserver(IObserver* observer);

   /**
    * Notifies all attached observers that the subject has been changed
    */
    virtual void notifyObservers();

protected:
    Subject();

private:
    std::set<IObserver*> observers;
};

#endif //SUBJECT_H