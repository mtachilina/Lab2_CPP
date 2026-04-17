#pragma once
#include <vector>
#include <queue>
#include <map>
#include <string>
#include "Eq.h"
#include "Msg.h"

class Teacher {
public:
    std::vector<Eq> eqs;
    std::queue<Msg> q;
    std::map<std::string, int> res;

    void load(std::string file);
    void simulate();
    void checkAll();
    void print();
};
