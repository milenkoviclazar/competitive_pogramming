#include <bits/stdc++.h>

using namespace std;

struct UnionFind {
    vector<int> p;
    vector<int> rank;
    UnionFind(int n) {
        p.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++) {
            p[i] = i;
            rank[i] = 0;
        }
    }
    int find_root(int x) {
        if (x == p[x]) {
            return x;
        }
        p[x] = find_root(p[x]);
        return p[x];
    }
    bool merge(int a, int b) {
        a = find_root(a);
        b = find_root(b);
        if (a == b) {
            return false;
        }
        if (rank[a] < rank[b]) {
            p[a] = b;
        } else {
            p[b] = a;
        }
        if (rank[a] == rank[b]) {
            rank[a]++;
        }
        return true;
    }
};


int main() {
    std::ios_base::sync_with_stdio(false);
    return 0;
}
