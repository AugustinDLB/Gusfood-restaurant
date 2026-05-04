#include <iostream>

#include "map.hpp"
#include "types.hpp"

void Map::map_init() {
  for (pos_x_t x = 0; x < MAP_X_SIZE; x++) {
    for (pos_y_t y = 0; y < MAP_Y_SIZE; y++) {
      if (x == 0 || x == MAP_X_SIZE - 1 || y == 0 || y == MAP_Y_SIZE - 1) {
        map[x][y] = MapState::BORDER;
      } else {
        map[x][y] = MapState::FREE;
      }
    }
  }
}

void Map::print_map() {
  for (pos_y_t y = 0; y < MAP_Y_SIZE; y++) {
    for (pos_x_t x = 0; x < MAP_X_SIZE; x++) {

      if (map[x][y] == MapState::BORDER) {
        std::cout << " / ";
      } else if (map[x][y] == MapState::PLAYER) {
        std::cout << " x ";
      } else if (map[x][y] == MapState::FREE) {
        std::cout << "___";
      } else {
        std::cout << '?';
      }
      if (x == MAP_X_SIZE - 1) {
        std::cout << std::endl;
      }
    }
  }
  std::cout << std::endl;
  std::cout << std::endl;
  std::cout << std::endl;
}

bool Map::is_area_clear(const pos_x_t &pos_x, const pos_y_t &pos_y,
                        const obj_size_t &obj_size) {
  return is_area_clear(pos_x + obj_size, pos_y + obj_size, pos_x - obj_size, pos_y - obj_size);
}

bool Map::is_area_clear(const pos_x_t &pos_x1, const pos_y_t &pos_y1,const pos_x_t &pos_x2, const pos_y_t &pos_y2) {
  const pos_x_t min_x = std::min(pos_x1,pos_x2);
  const pos_x_t max_x = std::max(pos_x1, pos_x2);
  const pos_y_t min_y = std::min(pos_y1,pos_y2);
  const pos_y_t max_y = std::max(pos_y1, pos_y2);

  for (pos_x_t x = min_x; x < max_x; x++) {
    for (pos_y_t y = min_y; y < max_y; y++) {
      if (is_out_of_map(x, y) || map[x][y] != MapState::FREE) {
        return false;
      }
    }
  }
  return true;
}


bool Map::is_out_of_map(const pos_x_t &x, const pos_y_t &y) {
  bool res = (x >= MAP_X_SIZE || y >= MAP_Y_SIZE || x < 0 || y < 0);
  if (res)
    std::cout << " out of map detected !" << std::endl;

  return res;
}

void Map::set_area(const pos_x_t &pos_x, const pos_y_t &pos_y,
                   const obj_size_t &obj_size, const MapState map_state) {
  set_area(pos_x + obj_size, pos_y + obj_size, pos_x - obj_size, pos_y - obj_size, map_state);
}


void Map::set_area(const pos_x_t &pos_x1, const pos_y_t &pos_y1,const pos_x_t &pos_x2, const pos_y_t &pos_y2, const MapState& map_state) {
  //std::cout << pos_x1 << "et" << pos_y1 << "et" << pos_x2 << "et" << pos_y2 << std::endl;

  const pos_x_t min_x = std::min(pos_x1,pos_x2);
  const pos_x_t max_x = std::max(pos_x1, pos_x2);
  const pos_y_t min_y = std::min(pos_y1,pos_y2);
  const pos_y_t max_y = std::max(pos_y1, pos_y2);

  for (pos_x_t x = min_x; x < max_x; x++) {
    std::fill(&map[x][min_y], &map[x][max_y], map_state);
  }
}