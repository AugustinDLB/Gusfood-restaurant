#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <string>

class IObservable;

class IObserver {

  friend class IObservable; /* Observable needs access to the update function
                               but now one else */

private:
  std::string message_from_observable;
  IObservable &observable;

public:
  IObserver(IObservable &observable);
  virtual ~IObserver() = default;

protected:
  virtual void update(const std::string &message_from_observable) = 0;
  void RemoveMeFromTheList();
};

#endif