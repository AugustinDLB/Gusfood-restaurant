#ifndef MODEL_HPP
#define MODEL_HPP

#include "dish.hpp"
#include "character.hpp"
#include "restau_config.h"

using empl_t = uint8_t;
using ordr_t = std::map<prio_t, std::queue<Dish>>; // Waiting queue for all dishes, according to their priority

class Model
{
private:
	Character player;
	empl_t employees;
	ordr_t orders;
	int timesAdd = 0;

public:
	int getAddTimes();
	void addByOne();
	// Factory pattern
	void order(const name_t name);
	void move_player_up();
    void move_player_down();
    void move_player_right();
    void move_player_left();
	Model();
};

void Model::Model() : player(Player(0,0,CHARACTER_SPEED)) {}

void Model::move_player_up() {
	player.move_up();
};
void Model::move_player_down() {
	player.move_down();
};
void Model::move_player_right() {
	player.move_right();
};
void Model::move_player_left() {
	player.move_left();
};

#endif