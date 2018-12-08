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

int main() {
//    freopen("/Users/milenkoviclazar/sandbox/competitive_programming/input.in", "r", stdin);
    std::ios_base::sync_with_stdio(false);
    while (!cin.eof()) {
        long long a, b, x, y;
        cin >> a >> b;
        if (cin.eof()) {
            break;
        }
        long long d = extended_euclidean(a, b, x, y);
        cout << x << " " << y << " " << d << endl;
    }


    return 0;
}
