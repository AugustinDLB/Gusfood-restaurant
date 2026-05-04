#ifndef OBSERVABLE_HPP
#define OBSERVABLE_HPP

#include <List>
#include <String>

class IObserver;

class IObservable
{
private:
    std::string message;
    std::list<IObserver *> list_observers;
public:
    void Attach(IObserver &observer);
    void Detach(IObserver &observer);
    virtual ~IObservable() = default;
protected:
    void notify();
};

#endif