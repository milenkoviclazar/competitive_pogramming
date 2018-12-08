#include <bits/stdc++.h>

using namespace std;

const int MAXV = 1e5 + 15;

vector<int> bipartiteness(int n, vector<int> *adj) {
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++) {
        if (color[i] != -1) {
            continue;
        }
        queue<int> q;
        color[i] = 0;
        for (q.push(i); !q.empty(); q.pop()) {
            int curr = q.front();
            for (auto &x : adj[curr]) {
                if (color[x] == -1) {
                    color[x] = 1 - color[curr];
                    q.push(x);
                } else if (color[x] + color[curr] != 1) {
                    return vector<int>();
                }
            }
        }
    }
    return color;
}


int n, m;
int main() {
    std::ios_base::sync_with_stdio(false);
    int tsts;
    cin >> tsts;
    for (int tNo = 0; tNo < tsts; tNo++) {
        int n, m;
        cin >> n >> m;
        vector<int> adj[MAXV];
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        cout << "Scenario #" << tNo + 1 << ":" << endl;
        auto ret = bipartiteness(n, adj);
        if (ret.empty()) {
            cout << "Suspicious bugs found!" << endl;
        } else {
            cout << "No suspicious bugs found!" << endl;
        }
    }
    return 0;
}
