#include <locale.h> 
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class Eq {
public:
    double a, b, c;
    double x1, x2;

    Eq(double A, double B, double C) {
        a = A;
        b = B;
        c = C;
        solve();
    }

    void solve() {
        double d = b*b - 4*a*c;

        if (d < 0) {
            x1 = x2 = 0;
        }
        else if (d == 0) {
            x1 = x2 = -b / (2*a);
        }
        else {
            double s = sqrt(d);
            x1 = (-b - s) / (2*a);
            x2 = (-b + s) / (2*a);
        }
    }

    bool check(double a1, double a2) {
        if (fabs(x1 - a1) < 1e-6 && fabs(x2 - a2) < 1e-6) return true;
        if (fabs(x1 - a2) < 1e-6 && fabs(x2 - a1) < 1e-6) return true;
        return false;
    }
};

class Msg {
public:
    Eq e;
    string name;
    int type; // 0 хор, 1 средний, 2 плохой
    double a1, a2;

    Msg(Eq eq, string n, int t) : e(eq) {
        name = n;
        type = t;
        make();
    }

    void make() {
        if (type == 0) {
            a1 = e.x1;
            a2 = e.x2;
        }
        else if (type == 1) {
            if (rand()%100 < 75) {
                a1 = e.x1;
                a2 = e.x2;
            }
            else {
                a1 = rand()%10;
                a2 = rand()%10;
            }
        }
        else {
            a1 = 0;
            a2 = 0;
        }
    }
};

class Teacher {
public:
    vector<Eq> eqs;
    queue<Msg> q;
    map<string, int> res;

    void load(string file) {
        ifstream f(file);

        if (!f) {
            cout << "Не получилось открыть файл: " << file << endl;
            return;
        }

        double a, b, c;
        while (f >> a >> b >> c) {
            eqs.push_back(Eq(a, b, c));
        }

        cout << "Загружено уравнений: " << eqs.size() << endl;
    }

    void simulate() {
        vector<string> names = { "Катя","Вика","Вова","Женя" };
        vector<int> types = { 0,1,2,0 };

        for (int i = 0; i < names.size(); i++) {
            for (int j = 0; j < eqs.size(); j++) {
                Msg m(eqs[j], names[i], types[i]);
                q.push(m);
            }
        }

        cout << "Писем на проверку: " << q.size() << endl;
    }

    void checkAll() {
        while (!q.empty()) {
            Msg m = q.front();
            q.pop();

            if (m.e.check(m.a1, m.a2)) {
                res[m.name]++;
            }
        }
    }

    void print() {
        cout << "\nРезультаты:\n";

        for (auto x : res) {
            cout << x.first << ": "
                << x.second << " из " << eqs.size() << endl;
        }
    }
};

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