#ifndef MAP_HPP
#define MAP_HPP

#include <map>

#include "types.hpp"

enum class MapState{
    PLAYER,
    BORDER,
    FREE
};

#define MAP_X_SIZE 20
#define MAP_Y_SIZE 20

class Map {
    public:
        MapState map[MAP_X_SIZE][MAP_Y_SIZE];
        void map_init();
        void print_map();
        bool is_area_clear(const pos_x_t& x, const pos_y_t& y, const obj_size_t& sz);
        bool is_area_clear(const pos_x_t &pos_x1, const pos_y_t &pos_y1,const pos_x_t &pos_x2, const pos_y_t &pos_y2);
        bool is_out_of_map(const pos_x_t &x, const pos_y_t &y);
        void set_area(const pos_x_t& x, const pos_y_t& y, const obj_size_t& sz, const MapState map_state);
        void set_area(const pos_x_t &pos_x1, const pos_y_t &pos_y1,const pos_x_t &pos_x2, const pos_y_t &pos_y2, const MapState& state);

};

#endif