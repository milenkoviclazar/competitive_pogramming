#include <bits/stdc++.h>

using namespace std;

void print_binary(long long x, int positions = 5) {
    vector<int> ret;
    for (int i = 0; i < positions; i++) {
        ret.push_back(x % 2);
        x >>= 1;
    }
    reverse(ret.begin(), ret.end());
    for (auto &d : ret) {
        cout << d;
    }
    cout << endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int n = 7;
    for (int s = n; s > 0; s = (s - 1) & n) {
        print_binary(s, 3);
    }
    return 0;
}
