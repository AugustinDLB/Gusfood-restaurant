#include "types.hpp"

struct CharacterPosChanged
{
    id_t id;
    pos_x_t x;
    pos_y_t y;
};

struct CharacterSpeedChanged
{
    id_t id;
    speed_t speed;
};
