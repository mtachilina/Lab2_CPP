#include "Eq.h"
#include "constants.h"
#include <cmath>

Eq::Eq(double A, double B, double C) {
    a = A;
    b = B;
    c = C;
    solve();
}

void Eq::solve() {
    double d = b*b - 4*a*c;

    if (d < 0) {
        x1 = x2 = 0;
        return;
    }

    if (d == 0) {
        x1 = x2 = -b / (2*a);
        return;
    }

    double s = sqrt(d);
    x1 = (-b - s) / (2*a);
    x2 = (-b + s) / (2*a);
}

bool Eq::check(double a1, double a2) {
    if (fabs(x1 - a1) < EPS && fabs(x2 - a2) < EPS) return true;
    if (fabs(x1 - a2) < EPS && fabs(x2 - a1) < EPS) return true;
    return false;
}
