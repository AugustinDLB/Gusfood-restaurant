#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "gusfood_model.hpp"
#include "view.hpp"
#include "view_listener.hpp"

class Controller : public ViewListener
{
public:
  Controller(View* view, GusFoodModel* model);

  View *view;
  GusFoodModel *model;

  // Inherited via View Listener
  virtual void move_player_down() override;
  virtual void move_player_up() override;
  virtual void move_player_right() override;
  virtual void move_player_left() override;
};

void Controller::move_player_down()
{
  this->model->move_player_down();
}

void Controller::move_player_up()
{
  this->model->move_player_up();
}

void Controller::move_player_right()
{
  this->model->move_player_right();
}

void Controller::move_player_left()
{
  this->model->move_player_left();
}

Controller::Controller(View *view, GusFoodModel *model)
{
  this->view = view;
  this->model = model;
}

#endif