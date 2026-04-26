#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "model.hpp"
#include "view.hpp"
#include "view_listener.hpp"

class Controller : public ViewListener
{
public:
  Controller(View *view, Model *model);

  View *view;
  Model *model;

  // Inherited via View Listener
  virtual void move_player_down() override;
  virtual void move_player_up() override;
  virtual void move_player_right() override;
  virtual void move_player_left() override;
};

Controller::move_player_down()
{
  this->model->move_player_down();
}

Controller::move_player_up()
{
  this->model->move_player_up();
}

Controller::move_player_right()
{
  this->model->move_player_right();
}

Controller::move_player_left()
{
  this->model->move_player_left();
}

Controller::Controller(View *view, Model *model)
{
  this->view = view;
  this->model = model;
}

#endif