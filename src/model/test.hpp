#include <iostream>

class Test {
    protected:
        void notify();
};

void Test::notify()
{
    // auto iterator = list_observers.begin();
    // while (iterator != list_observers.end())
    // {
    //     (*iterator)->update(message);
    //     ++iterator;
    // }
    std::cout << "notification envoyée par le modèle" << std::endl;
}