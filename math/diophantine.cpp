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

long long gcd(long long a, long long b) {
    return b != 0 ? gcd(b, a % b) : a;
}

bool find_one(long long a, long long b, long long c, long long &x, long long &y) {
    if (a == 0 && b == 0) {
        return c == 0;
    }
    long long d = extended_euclidean(abs(a), abs(b), x, y);
    if (abs(c) % d != 0) {
        return false;
    }
    if (a < 0) {
        x *= -1;
    }
    if (b < 0) {
        y *= -1;
    }
    x *= c / d;
    y *= c / d;
    return true;
}

long long count_solutions(long long a, long long b, long long c, long long min_x, long long max_x, long long min_y,
                          long long max_y) {
    long long x, y;
    if (a == 0 && b == 0) {
        if (c == 0) {
            return (max_x - min_x + 1) * (max_y - min_y + 1);
        } else {
            return 0;
        }
    }
    if (a == 0) {
        if (abs(c) % abs(b) == 0) {
            y = c / b;
            if (min_y <= y && y <= max_y) {
                return (max_x - min_x + 1);
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    }
    if (b == 0) {
        if (abs(c) % abs(a) == 0) {
            x = c / a;
            if (min_x <= x && x <= max_x) {
                return (max_y - min_y + 1);
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    }
    if (!find_one(a, b, c, x, y)) {
        return 0;
    }

    long long x0 = x;
    long long y0 = y;
    long long d = gcd(abs(a), abs(b));
    a /= d;
    b /= d;
    long long cnt = (min_x - x) / b;
    x = x + cnt * b;
    if (x < min_x) {
        x += abs(b);
    }
    if (x > max_x) {
        return 0;
    }
    long long x1l = x;

    cnt = (max_x - x) / b;
    x = x + cnt * b;
    if (x > max_x) {
        x -= abs(b);
    }
    long long x1r = x;
    if (x1l > x1r) {
        swap(x1l, x1r);
    }

    x = x0;
    y = y0;
    cnt = (min_y - y) / a;
    y = y + cnt * a;
    x = x - cnt * b;
    if (y < min_y) {
        y += abs(a);
        x -= abs(b);
    }
    if (y > max_y) {
        return 0;
    }
    long long x2l = x;

    cnt = (max_y - y) / a;
    y = y + cnt * a;
    x = x - cnt * b;
    if (y > max_y) {
        y -= abs(a);
        x += abs(b);
    }
    long long x2r = x;
    if (x2l > x2r) {
        swap(x2l, x2r);
    }
//    assert(min_x <= x1l && x1l <= max_x);
//    assert(min_x <= x1r && x1r <= max_x);
//    assert(min_x <= x2l && x2l <= max_x);
//    assert(min_x <= x2r && x2r <= max_x);
    long long xl = max(x1l, x2l);
    long long xr = min(x1r, x2r);
    if (xl > xr) {
        return 0;
    }
    return (xr - xl) / abs(b) + 1;
}

int main() {
    std::ios_base::sync_with_stdio(false);
//    freopen("/Users/milenkoviclazar/sandbox/competitive_programming/input.in", "r", stdin);
    long long a, b, c, x_min, x_max, y_min, y_max;
    cin >> a >> b >> c >> x_min >> x_max >> y_min >> y_max;

    a = -a;
    b = -b;

    cout << count_solutions(a, b, c, x_min, x_max, y_min, y_max) << endl;

    return 0;
}
