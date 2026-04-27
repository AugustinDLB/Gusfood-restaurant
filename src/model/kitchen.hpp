#ifndef KITCHEN_HPP
#define KITCHEN_HPP

#include <queue>
#include <map>

using empl_t = uint8_t;
using ordr_t = std::map<prio_t, std::queue<Dish>>; // Waiting queue for all dishes, according to their priority

class Kitchen
{
private:
    Kitchen() = default;
    empl_t employees;
    ordr_t orders;

public:

    // Singelton pattern
    static Kitchen &getInstance()
    {
        static Kitchen kitchen;
        return kitchen;
    }
    Kitchen(const Kitchen &kitch) = delete;
    Kitchen &operator=(const Kitchen &) = delete;

    // Factory pattern
    void order(const name_t name)
    {
        if(name == "Pizza"){
            orders[0].push(Pizza()); 
        } else if(name == "Pasta"){
            orders[1].push(Pasta()); 
        }
    }
};

#endif