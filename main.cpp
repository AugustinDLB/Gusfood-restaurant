#include "src/gusfood_model.hpp"
#include "src/view.hpp"
#include "build/gusfood_config.h"
#include "src/controller.hpp"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    GusFoodModel m;
    View v(m);
    Controller c(v, m);
    m.Attach(v);
    v.setListener(&c);
    v.configure();
    v.run();

    return 0;
}