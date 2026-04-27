#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <String>

class IObservable;

class IObserver
{
private:
  std::string message_from_observable;

public:
  IObserver(IObservable &observable);
  void RemoveMeFromTheList();
  virtual ~IObserver() {};
  virtual void update(const std::string &message_from_observable) = 0;
  static int static_number;
  int number;
  IObservable &observable;
};

#endif