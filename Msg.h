#pragma once
#include <string>
#include "Eq.h"

class Msg {
public:
    Eq e;
    std::string name;
    int type;
    double a1, a2;

    Msg(Eq eq, std::string n, int t);

    void make();
};

