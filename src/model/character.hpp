#ifndef CHARACTER_HPP
#define CHARACTER_HPP

using pos_x_t = int;
using pos_y_t = int;
using speed_t = int;
using id_t = int;

class Character
{
private:
    pos_x_t pos_x;
    pos_y_t pos_y;
    speed_t speed;
    id_t id;

public:
    Character() = default;
    id_t Character(const pos_x_t x, const pos_y_t y, const speed_t s) : pos_x(x), pos_y(y), speed(s) {
        static id_t id_index = 0;
        id_index++;
        return id_index++;
    }

    void move_up();
    void move_down();
    void move_right();
    void move_left();
};

void Character::move_up()
{
    pos_y += speed;
}

void Character::move_down()
{
    pos_y -= speed;
}

void Character::move_right()
{
    pos_x += speed;
}

void Character::move_left()
{
    pos_x -= speed;
}

#endif