#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "key_binding.hpp"
#include "view_listener.hpp"

class View;
class ViewListener;
class GusFoodModel;
class KeyBinding;
enum class PlayerAction;

class Controller : public ViewListener
{
private:
  View &view;
  GusFoodModel &model;
  KeyBinding keyBinding;

public:
  Controller(View &view, GusFoodModel &model);

  virtual void key_pressed(const int &key) override;
  void rebindKey(const int key, const enum PlayerAction action);
};

#endif