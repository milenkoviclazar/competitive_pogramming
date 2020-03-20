#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 55;

int a, b;
vector<int> adj[MAXN];
bool visited[MAXN];
int pr[MAXN];

int augment(int curr) {
    if (curr == -1) {
        return 1;
    }
    if (visited[curr]) {
        return 0;
    }
    visited[curr] = true;
    for (auto x : adj[curr]) {
        if (augment(pr[x])) {
            pr[x] = curr;
            pr[curr] = x;
            return 1;
        }
    }
    return 0;
}

int matching(int a, int b) {
    memset(pr, -1, sizeof pr);
    int ret = 0;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            visited[j] = false;
        }
        ret += augment(i);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> a >> b;
    cout << matching(a, b) << endl;
    return 0;
}
