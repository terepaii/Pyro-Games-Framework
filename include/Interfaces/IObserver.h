#ifndef IOBSERVER_H
#define IOBSERVER_H

class Subject;

/**
* Defines an interface for observing subjects. These can be attached and unattached
* from subjects.
*/
class IObserver
{
public:
    virtual ~IObserver() {}

    /**
    * abstract method that is called when subjects notify this observer
    */
    virtual void update(const Subject* subject) = 0;

protected:
    IObserver() {}
};

#endif //IOBSERVER_H