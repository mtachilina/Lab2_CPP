#include <locale.h>
#include <ctime>
#include <cstdlib>
#include "Teacher.h"

int main() {
    setlocale(LC_ALL, "Rus");
    srand(time(0));

    Teacher t;

    t.load("eq.txt");
    t.simulate();
    t.checkAll();
    t.print();

    return 0;
}
