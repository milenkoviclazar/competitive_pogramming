#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e7 + 17;

vector<int> primes;
int lp[MAXN];

int main() {
    std::ios_base::sync_with_stdio(false);
    for (int i = 2; i < MAXN; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            primes.push_back(i);
        }
        for (auto &p : primes) {
            if (p > lp[i]) {
                break;
            }
            if (i * p >= MAXN) {
                break;
            }
            lp[i * p] = p;
        }
    }
    return 0;
}
