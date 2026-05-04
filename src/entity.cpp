#include "entity.hpp"
#include "types.hpp"

Entity::Entity(const pos_x_t &x, const pos_y_t &y, const obj_size_t &sz,
               const speed_t &s)
    : pos_x(x), pos_y(y), obj_size(sz), speed(s) {
  static id_t id_count = 0;
  this->id = id_count++;
}
pos_x_t Entity::get_pos_x() { return pos_x; }
pos_y_t Entity::get_pos_y() { return pos_y; }
obj_size_t Entity::get_obj_size() { return obj_size; };
id_t Entity::get_id() { return id; };
void Entity::set_speed(const speed_t s) { speed = s; }
void Entity::set_pos_x(const pos_x_t &x) { pos_x = x; }
void Entity::set_pos_y(const pos_y_t &y) { pos_y = y; }
speed_t Entity::get_speed() { return speed; }
