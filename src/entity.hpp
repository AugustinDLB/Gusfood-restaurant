#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "types.hpp"

class Entity {
private:
  pos_x_t pos_x;
  pos_y_t pos_y;
  id_t id;
  obj_size_t obj_size;
  speed_t speed;
public:
    Entity() {};
    Entity(const pos_x_t& x, const pos_y_t& y,const obj_size_t& sz, const speed_t& s);
    pos_x_t get_pos_x();
    pos_y_t get_pos_y();
     void set_speed(const speed_t s);
     void set_pos_x(const pos_x_t& x);
   void set_pos_y(const pos_y_t& y);
   speed_t get_speed();

    obj_size_t get_obj_size();
    id_t get_id();
};

#endif