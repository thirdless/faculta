#include <iostream>
#include <math.h>
#include <ctime>

typedef unsigned long long int ull;

using namespace std;

ull min(ull a, ull b) {
    if (a > b) return b;
    else return a;
}

ull num_digits(ull num) {
    ull digits = 0;
    while (num != 0) {
        digits++;
        num = num / 10;
    }
    return digits;
}

ull mult1(ull x, ull y) {

    ull lenx, leny, len, xs, xd, ys, yd, p1, p2, p3, p4, m;

    if (x >= 10 && y >= 10) {
        lenx = num_digits(x);
        leny = num_digits(y);
        len = min(lenx, leny);

        m = len / 2;

        xs = x / pow(10, m);
        xd = x % (ull)pow(10, m);
        ys = y / pow(10, m);
        yd = y % (ull)pow(10, m);
        p1 = mult1(xs, ys);
        p2 = mult1(xd, yd);
        p3 = mult1(xs, yd);
        p4 = mult1(xd, ys);
        return p1 * pow(10, 2 * m) + p2 + (p3 + p4) * pow(10, m);
    }
    else return x * y;
}

ull mult2(ull x, ull y) {
    ull lenx, leny, len, xs, xd, ys, yd, p1, p2, p3, m;

    if (x >= 10 && y >= 10) {
        lenx = num_digits(x);
        leny = num_digits(y);
        len = min(lenx, leny);

        m = len / 2;

        xs = x / pow(10, m);
        xd = x % (ull)pow(10, m);
        ys = y / pow(10, m);
        yd = y % (ull)pow(10, m);
        p1 = mult2(xs, ys);
        p2 = mult2(xd, yd);
        p3 = mult2(xs + xd, yd + ys);
        return p1 * pow(10, 2 * m) + p2 + (p3 - p1 - p2) * pow(10, m);
    }
    else return x * y;
}

int main() {
    ull x = 123412312;
    ull y = 213123123;
    clock_t start;
    double t1, t2;

    start = clock();
    cout << mult1(x, y) << endl;
    t1 = ((double)(clock() - start)) / CLOCKS_PER_SEC;

    start = clock();
    cout << mult2(x, y) << endl;
    t2 = ((double)(clock() - start)) / CLOCKS_PER_SEC;

    cout << "T1: " << t1 << "s\nT2: " << t2 << "s" << endl;
}
