#pragma once

class Eq {
public:
    double a, b, c;
    double x1, x2;

    Eq(double A, double B, double C);

    void solve();
    bool check(double a1, double a2);
};
