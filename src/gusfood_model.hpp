#ifndef GUS_FOOD_MODEL_HPP
#define GUS_FOOD_MODEL_HPP

#include <map>

#include "observable.hpp"
#include "entity.hpp"
#include "types.hpp"
#include "map.hpp"


class GusFoodModel : public IObservable
{
private:
	std::map<id_t,Entity> entities;
	id_t player_id;
	Map map;
	void move_entity(const id_t id, const mov_x_t mov_x, const mov_y_t mov_y);


public:
	void move_player_up();
	void move_player_down();
	void move_player_right();
	void move_player_left();
	pos_x_t get_player_pos_x();
	pos_y_t get_player_pos_y();
	GusFoodModel();
};

#endif