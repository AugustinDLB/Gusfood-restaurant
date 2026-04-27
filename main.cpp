#include <iostream>

#include "view.hpp"
#include "gusfood_model.hpp"
#include "controller.hpp"

using namespace std;

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{

    GusFoodModel m;
    View v(m);
    Controller c(&v, &m);
    m.Attach(v);
    v.setListener(&c);
    v.configure();
    v.run();

    return 0;
}