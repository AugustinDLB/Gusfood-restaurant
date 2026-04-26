#ifndef VIEW_LISTENER_HPP
#define VIEW_LISTENER_HPP

class ViewListener
{
public:
	virtual void userEnterAdd() = 0;
	virtual void userEnterAddShow() = 0;
	
	virtual void move_player_down() = 0;
	virtual void move_player_up() = 0;
	virtual void move_player_right() = 0;
	virtual void move_player_left() = 0;
};

#endif