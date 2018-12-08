#include <bits/stdc++.h>

using namespace std;

struct Dinic {
    struct FlowEdge {
        int from;
        int to;
        long long flow;
        long long cap;

        FlowEdge(int _from, int _to, long long _flow, long long _cap) : from(_from), to(_to), flow(_flow), cap(_cap) {}
    };

    const long long oo = 0x7f7f7f7f7f7f7f7f;

    vector<vector<int>> adj;
    vector<FlowEdge> edges;
    vector<int> lvl;
    vector<int> ptr;
    int s, t;

    Dinic() {
        s = 0;
        t = 0;
    }

    Dinic(int n, int s, int t) {
        this->s = s;
        this->t = t;
        adj.resize(n);
        lvl.resize(n);
        ptr.resize(n);
    }

    void add_edge(int from, int to, long long cap) {
        edges.emplace_back(from, to, 0, cap);
        adj[from].emplace_back(edges.size() - 1); // 0

        edges.emplace_back(to, from, 0, 0);
        adj[to].emplace_back(edges.size() - 1); // 1
    }

    bool dfs(int curr, long long lim) {
        if (curr == t) {
            return true;
        }
        if (lim <= 0) {
            return false;
        }
        for (; ptr[curr] < adj[curr].size(); ptr[curr]++) {
            int id = adj[curr][ptr[curr]];
            int next = edges[id].to;
            if (lvl[next] != lvl[curr] + 1) {
                continue;
            }
            if (edges[id].cap - edges[id].flow < lim) {
                continue;
            }
            if (dfs(next, lim)) {
                edges[id].flow += lim;
                edges[id ^ 1].flow -= lim;
                return true;
            }

        }
        return false;
    }

    bool bfs(long long lim) {
        fill(lvl.begin(), lvl.end(), -1);
        queue<int> q;
        lvl[s] = 0;
        for (q.push(s); !q.empty(); q.pop()) {
            int curr = q.front();
            for (auto &id : adj[curr]) {
                int next = edges[id].to;
                if (lvl[next] != -1) {
                    continue;
                }
                if (edges[id].cap - edges[id].flow < lim) {
                    continue;
                }
                lvl[next] = lvl[curr] + 1;
                q.push(next);
            }
        }
        return lvl[t] != -1;
    }

    long long maxflow() {
        long long flow = 0;
        for (long long limit = 1LL << 61; limit >= 1; ) {
            if (!bfs(limit)) {
                limit >>= 1;
                continue;
            }
//            cout << limit << endl;
            fill(ptr.begin(), ptr.end(), 0);
            long long currflow = 0;
            while (dfs(s, limit)) {
                flow += limit;
            }
        }
        return flow;
    }
};

int n, m;

int main() {
    std::ios_base::sync_with_stdio(false);
//    freopen("/Users/milenkoviclazar/sandbox/competitive_programming/input.in", "r", stdin);
    cin >> n >> m;
    Dinic d(n, 0, n - 1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        d.add_edge(a, b, c);
        d.add_edge(b, a, c);
    }
    cout << d.maxflow() << endl;
    return 0;
}
