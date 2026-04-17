#include "Msg.h"
#include "constants.h"
#include <cstdlib>

Msg::Msg(Eq eq, std::string n, int t) : e(eq) {
    name = n;
    type = t;
    make();
}

void Msg::make() {
    if (type == 0) {
        a1 = e.x1;
        a2 = e.x2;
        return;
    }

    if (type == 1 && rand()%100 < GOOD_PROB) {
        a1 = e.x1;
        a2 = e.x2;
        return;
    }

    if (type == 1) {
        a1 = rand()%10;
        a2 = rand()%10;
        return;
    }

    a1 = 0;
    a2 = 0;
}
