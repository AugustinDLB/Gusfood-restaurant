#ifndef OBSERVABLE_HPP
#define OBSERVABLE_HPP

#include <List>
#include <String>
#include <iostream>

class IObserver;

class IObservable
{
private:
    std::string message;
    std::list<IObserver *> list_observers;

public:
    void Attach(IObserver &observer);
    void Detach(IObserver &observer);
    virtual ~IObservable() {};

protected:
    void notify();
};

#endif