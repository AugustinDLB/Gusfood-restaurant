#include <iostream>

#include "../build/gusfood_config.h"
#include "entity.hpp"
#include "gusfood_model.hpp"
#include "map.hpp"
#include "types.hpp"

#define PLAYER_SPEED 1
#define PLAYER_INIT_POS MAP_X_SIZE / 2
#define PLAYER_SIZE 3

GusFoodModel::GusFoodModel() {
  Entity player(PLAYER_INIT_POS, PLAYER_INIT_POS, PLAYER_SIZE, PLAYER_SPEED);
  player_id = player.get_id();
  entities[player_id] = player;
  map.map_init();
}

void GusFoodModel::move_player_up() {
  move_entity(player_id, 0, -PLAYER_SPEED);
};
void GusFoodModel::move_player_down() {
  move_entity(player_id, 0, PLAYER_SPEED);
};
void GusFoodModel::move_player_right() {
  move_entity(player_id, PLAYER_SPEED, 0);
};
void GusFoodModel::move_player_left() {
  move_entity(player_id, -PLAYER_SPEED, 0);
};

void GusFoodModel::move_entity(const id_t id, const mov_x_t mov_x,
                               const mov_y_t mov_y) {
  // check if future entity position is not in collision with an other entity !
  const pos_x_t &pos_x = entities[id].get_pos_x();
  const pos_y_t &pos_y = entities[id].get_pos_y();
  const obj_size_t &obj_size = entities[id].get_obj_size();

  map.set_area(pos_x, pos_y, obj_size, MapState::FREE);
  const bool is_area_clear =
      map.is_area_clear(pos_x + mov_x, pos_y + mov_y, obj_size);

   if (is_area_clear) {
    std::cout << "clear ! " << std::endl;
     map.set_area(pos_x + mov_x, pos_y + mov_y, obj_size, MapState::PLAYER);

     entities[player_id].set_pos_x(pos_x + mov_x);
     entities[player_id].set_pos_y(pos_y + mov_y);
     // notify();

   } else {
      std::cout << "UNCLEAR " << std::endl;
     map.set_area(pos_x, pos_y, obj_size, MapState::PLAYER);
   }
   map.print_map();

}

pos_x_t GusFoodModel::get_player_pos_x() {
  return entities[player_id].get_pos_x();
}

pos_y_t GusFoodModel::get_player_pos_y() {
  return entities[player_id].get_pos_y();
}
