#include <bits/stdc++.h>

using namespace std;

pair<long long, long long> fib(long long idx) {
    if (idx == 0) {
        return {0, 1};
    }
    auto tmp = fib(idx >> 1);
    long long a = 2 * tmp.first * tmp.second - tmp.first * tmp.first;
    long long b = tmp.first * tmp.first + tmp.second * tmp.second;
    if (idx & 1) {
        return {b, a + b};
    }
    return {a, b};
}

int main() {
    std::ios_base::sync_with_stdio(false);

    return 0;
}
