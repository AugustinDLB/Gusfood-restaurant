#ifndef VIEW_HPP
#define VIEW_HPP

#include <List>

#include "../build/gusfood_config.h"
#include "observer.hpp"
#include "raylib.h"
#include "view_listener.hpp"

class View : public IObserver {
private:
  int screenWidth;
  int screenHeight;
  ViewListener* listener;

public:
  View(IObservable &observable);
  View(const View &) = delete;
  virtual ~View() {};
  void setListener(ViewListener * listener);

  // GUI CODE
  void configure();
  void run();
  void update(const std::string &message_from_observable) override;
};

#endif