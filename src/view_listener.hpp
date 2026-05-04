#ifndef VIEW_LISTENER_HPP
#define VIEW_LISTENER_HPP

class ViewListener
{
public:	
	virtual ~ViewListener() = default;
	virtual void key_pressed(const int& key) = 0;
};

#endif