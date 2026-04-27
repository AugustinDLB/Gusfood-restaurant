#ifndef GUS_FOOD_MODEL_HPP
#define GUS_FOOD_MODEL_HPP

#include "dish.hpp"
#include "character.hpp"
#include "restau_config.h"
#include "observable.hpp"
#include "test.hpp"

using empl_t = uint8_t;
// using ordr_t = std::map<prio_t, std::queue<Dish>>; // Waiting queue for all dishes, according to their priority

class GusFoodModel : public IObservable
{
private:
	Character player;
	empl_t employees;
	// ordr_t orders;
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
	GusFoodModel();
};

GusFoodModel::GusFoodModel() : player(Character(0, 0, CHARACTER_SPEED)) {}

void GusFoodModel::move_player_up()
{
	player.move_up();
	notify();
};
void GusFoodModel::move_player_down()
{
	player.move_down();
	notify();
};
void GusFoodModel::move_player_right()
{
	player.move_right();
	notify();
};
void GusFoodModel::move_player_left()
{
	player.move_left();
	notify();
};

#endif