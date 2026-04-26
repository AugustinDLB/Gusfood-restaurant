#include <iostream>

#include "view.hpp"
#include "controller.hpp"

using namespace std;

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    View v;
    Controller c;  
    v.setListener(&c);
    v.configure();
    v.run();

    return 0;
}