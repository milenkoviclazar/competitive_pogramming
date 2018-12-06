#include <bits/stdc++.h>

using namespace std;

const int MAXV = 1000;
const int oo = 0x7f7f7f7f;

int pre[MAXV];
int cap[MAXV][MAXV];
int n, m;
vector<int> adj[MAXV];

int bfs(int source, int sink) {
    bool visited[MAXV];
    for (int i = 0; i < MAXV; i++) {
        visited[i] = false;
    }
    visited[source] = true;
    queue<pair<int, int>> q;
    for (q.push({source, oo}); !q.empty(); q.pop()) {
        auto [curr, dist] = q.front();
        for (auto &x : adj[curr]) {
            if (visited[x]) {
                continue;
            }
            int newdist = min(dist, cap[curr][x]);
            if (newdist <= 0) {
                continue;
            }
            visited[x] = true;
            pre[x] = curr;
            q.push({x, newdist});
            if (x == sink) {
                return newdist;
            }
        }
    }
    return 0;
}

int edmonds_karp(int source, int sink) {
    int flow = 0;
    memset(pre, -1, sizeof pre);
    for (int currflow = bfs(source, sink); currflow != 0; currflow = bfs(source, sink)) {
        flow += currflow;
        for (int v = sink; pre[v] != -1; v = pre[v]) {
            int u = pre[v];
            cap[u][v] -= currflow;
            cap[v][u] += currflow;
        }
        memset(pre, -1, sizeof pre);
    }
    return flow;
}

int main() {
    std::ios_base::sync_with_stdio(false);
//    freopen("/Users/milenkoviclazar/sandbox/competitive_programming/input.in", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        cap[a][b] += c;
    }

    cout << edmonds_karp(0, n - 1) << endl;
    return 0;
}
