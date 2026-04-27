#ifndef TASK_HPP
#define TASK_HPP

#include <iostream>
#include <string>
#include <chrono>
#include <thread>

#define PIZZA_DURATION 3 // 3 minutes to prepare !
#define PASTA_DURATION 1

using prio_t = uint8_t;
using name_t = std::string;
using func_t = void (*)();
using dura_t = uint8_t; // duration of the task in minutes

class Dish
{
public:
    Dish(const name_t nm, const prio_t prio, const func_t func, const dura_t dur) : name(nm), function(func), duration(dur)
    {
    }
    void put_to_hoven();

    name_t get_name() const { return name; }

    // enum steps;

    virtual ~Dish() = default;

protected:
    name_t name;
    func_t function;
    dura_t duration;
};

class Pizza : public Dish
{
public:
    Pizza() : Dish("Pizza", 0, nullptr, PIZZA_DURATION) {}
};

class Pasta : public Dish
{
public:
    Pasta() : Dish("Pasta", 0, nullptr, PASTA_DURATION) {}
};

#endif