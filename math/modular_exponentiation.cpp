#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll mod_exp(ll a, ll p, ll m) {
    ll ret = 1;
    for (; p; p >>= 1) {
        if (p & 1) {
            ret = ret * a % m;
        }
        a = a * a % m;
    }
    return ret;
}

ll mod_inv(ll a, ll m) {
    return mod_exp(a, m - 2, m);
}

int main() {
    ios_base::sync_with_stdio(false);
    ll M = 31337;
    for (int i = 0; i < 100; i++) {
        cout << i * mod_inv(i, M) % M << endl;
    }
    return 0;
}
