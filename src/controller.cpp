#include "gusfood_model.hpp"
#include "view.hpp"
#include "key_binding.hpp"
#include "player_action.hpp"
#include "controller.hpp"

void Controller::key_pressed(const int &key)
{
  // Obtenir l'action logique sans dépendre directement de la touche
  PlayerAction *action = keyBinding.getAction(key);

  if (action == nullptr)
    return;

  // Le Model IGNORE complètement les touches, il ne connaît que les actions !
  switch (*action)
  {
  case PlayerAction::MOVE_LEFT:
    model.move_player_left();
    break;
  case PlayerAction::MOVE_RIGHT:
    model.move_player_right();
    break;
  case PlayerAction::MOVE_UP:
    model.move_player_up();
    break;
  case PlayerAction::MOVE_DOWN:
    model.move_player_down();
    break;
  }
}

Controller::Controller(View &view, GusFoodModel &model)
    : view(view), model(model)
{
}

void Controller::rebindKey(const int key, const PlayerAction action)
{
  keyBinding.rebindKey(key, action);
}