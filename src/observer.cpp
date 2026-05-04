#include "observer.hpp"
#include "observable.hpp"

IObserver::IObserver(IObservable &observable) : observable(observable)
{
  this->observable.Attach(*this);
}

void IObserver::RemoveMeFromTheList()
{
  observable.Detach(*this);
}

