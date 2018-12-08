#include <bits/stdc++.h>

using namespace std;

long long extended_euclidean(long long a, long long b, long long &x, long long &y) {
    long long xa = 1;
    long long ya = 0;
    x = 0;
    y = 1;
    while (a % b != 0) {
        long long newb = a % b;
        long long q = a / b;
        long long newx = xa - x * q;
        long long newy = ya - y * q;
        xa = x;
        ya = y;
        x = newx;
        y = newy;
        a = b;
        b = newb;
    }
    return b;
}

bool find_one(long long a, long long b, long long c, long long &x, long long &y) {
    if (a == 0 && b == 0) {
        return c == 0;
    }
    long long d = extended_euclidean(abs(a), abs(b), x, y);
    if (c % d != 0) {
        return false;
    }
    x *= c / d;
    y *= c / d;
    if (a < 0) {
        x *= -1;
    }
    if (b < 0) {
        y *= -1;
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);
//    freopen("/Users/milenkoviclazar/sandbox/competitive_programming/input.in", "r", stdin);
    long long a, b, c;
    int tsts;
    cin >> tsts;
    for (int tNo = 0; tNo < tsts; tNo++) {
        cin >> a >> b >> c;
//        cout << a << b << c << endl;
        long long x, y;
        cout << "Case " << tNo + 1 << ": " << (find_one(a, b, c, x, y) ? "Yes" : "No") << endl;
    }


    return 0;
}
