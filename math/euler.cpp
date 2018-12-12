#include <bits/stdc++.h>

using namespace std;

long long phi(long long n) {
    long long ret = n;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            n /= i;
        }
        ret -= ret / i;
    }
    if (n > 1) {
        ret -= ret / n;
    }
    return ret;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    long long n;
    cin >> n;
    cout << phi(n) << endl;
    return 0;
}
