#include <bits/stdc++.h>

using namespace std;

const int MAXVAL = 1e6 + 16;
const int MAXTREE = MAXVAL * 6 * 4;

struct LazySegmentTree {
    int n, t[MAXTREE], lazy[MAXTREE];
    int oo = 0x7f7f7f7f;

    void build(int a[], int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
            lazy[v] = 0;
        } else {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            t[v] = t[v * 2] + t[v * 2 + 1];
            lazy[v] = 0;
        }
    }

    void push(int v) {
        t[v * 2] += lazy[v];
        lazy[v * 2] += lazy[v];
        t[v * 2 + 1] += lazy[v];
        lazy[v * 2 + 1] += lazy[v];
        lazy[v] = 0;
    }

    void update(int v, int tl, int tr, int l, int r, int add) {
        if (l > r) {
            return;
        }
        if (l == tl && tr == r) {
            t[v] += add;
            lazy[v] += add;
        } else {
            push(v);
            int tm = (tl + tr) / 2;
            update(v * 2, tl, tm, l, min(r, tm), add);
            update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, add);
            t[v] = max(t[v * 2], t[v * 2 + 1]);
        }
    }

    int query(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return -oo;
        }
        if (l <= tl && tr <= r) {
            return t[v];
        }
        push(v);
        int tm = (tl + tr) / 2;
        return max(query(v * 2, tl, tm, l, min(r, tm)),
                   query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }
};

LazySegmentTree segtree;

int n, r;
vector<tuple<int, int, int>> points;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> r;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points.emplace_back(x + y, y - x, 1);
        points.emplace_back(x + y + r + r, y - x, -1);
    }
    sort(points.begin(),
         points.end(),
         [](auto &a, auto &b) {
             if (get<0>(a) != get<0>(b)) {
                 return get<0>(a) < get<0>(b);
             }
             return get<2>(a) > get<2>(b);
         });
    int ret = 0;
    for (auto p : points) {
        int y = get<1>(p) + 2 * MAXVAL;
        int v = get<2>(p);
        segtree.update(1, 0, 6 * MAXVAL, y, y + r + r, v);
        ret = max(ret, segtree.query(1, 0, 6 * MAXVAL, 0, 6 * MAXVAL));
    }
    cout << ret << endl;
    return 0;
}
