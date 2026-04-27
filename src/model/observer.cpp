#include "observer.hpp"
#include "observable.hpp"

#include <iostream>

IObserver::IObserver(IObservable &observable) : observable(observable)
{
  this->observable.Attach(*this);
  std::cout << "Hi, I'm the Observer \"" << ++static_number << "\".\n";
  number = static_number;
}

void IObserver::RemoveMeFromTheList()
{
  observable.Detach(*this);
  std::cout << "Observer \"" << number << "\" removed from the list.\n";
}

int IObserver::static_number = 0;
