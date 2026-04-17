#include "Teacher.h"
#include <fstream>
#include <iostream>

void Teacher::load(std::string file) {
    std::ifstream f(file);

    if (!f) {
        std::cout << "Не получилось открыть файл: " << file << std::endl;
        return;
    }

    double a, b, c;
    while (f >> a >> b >> c) {
        eqs.push_back(Eq(a, b, c));
    }

    std::cout << "Загружено уравнений: " << eqs.size() << std::endl;
}

void Teacher::simulate() {
    std::vector<std::string> names = { "Катя","Вика","Вова","Женя" };
    std::vector<int> types = { 0,1,2,0 };

    for (int i = 0; i < names.size(); i++) {
        for (int j = 0; j < eqs.size(); j++) {
            Msg m(eqs[j], names[i], types[i]);
            q.push(m);
        }
    }

    std::cout << "Писем на проверку: " << q.size() << std::endl;
}

void Teacher::checkAll() {
    while (!q.empty()) {
        Msg m = q.front();
        q.pop();

        if (m.e.check(m.a1, m.a2)) {
            res[m.name]++;
        }
    }
}

void Teacher::print() {
    std::cout << "\nРезультаты:\n";

    for (auto x : res) {
        std::cout << x.first << ": "
            << x.second << " из " << eqs.size() << std::endl;
    }
}
