#include <iostream>

#include "observable.hpp"
#include "observer.hpp"

void IObservable::notify()
{
    auto iterator = list_observers.begin();
    while (iterator != list_observers.end())
    {
        (*iterator)->update(message);
        ++iterator;
    }
    std::cout << "notification envoyée par le modèle" << std::endl;
}

void IObservable::Attach(IObserver &observer)
{
    list_observers.push_back(&observer);
}
void IObservable::Detach(IObserver &observer)
{
    list_observers.remove(&observer);
}