#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const long long EPS = 1e-9;
const long long oo = 1e9;

int gauss_doubles(vector<vector<double> > a, vector<double> &ans) {
    int n = (int) a.size();
    int m = (int) a[0].size() - 1;

    vector<int> where(m, -1);
    for (int col = 0, row = 0; col < m && row < n; ++col) {
        int sel = row;
        for (int i = row; i < n; ++i)
            if (abs(a[i][col]) > abs(a[sel][col]))
                sel = i;
        if (abs(a[sel][col]) < EPS)
            continue;
        for (int i = col; i <= m; ++i)
            swap(a[sel][i], a[row][i]);
        where[col] = row;

        for (int i = 0; i < n; ++i)
            if (i != row) {
                double c = a[i][col] / a[row][col];
                for (int j = col; j <= m; ++j)
                    a[i][j] -= a[row][j] * c;
            }
        ++row;
    }

    ans.assign(m, 0);
    for (int i = 0; i < m; ++i)
        if (where[i] != -1)
            ans[i] = a[where[i]][m] / a[where[i]][i];
    for (int i = 0; i < n; ++i) {
        double sum = 0;
        for (int j = 0; j < m; ++j)
            sum += ans[j] * a[i][j];
        if (abs(sum - a[i][m]) > EPS)
            return 0;
    }

    for (int i = 0; i < m; ++i)
        if (where[i] == -1)
            return oo;
    return 1;
}

int gauss_ll(vector<vector<long long> > a, vector<long long> &ans) {
    ll n = (ll) a.size();
    ll m = (ll) a[0].size() - 1;

    vector<ll> where(m, -1);
    for (ll col = 0, row = 0; col < m && row < n; ++col) {
        ll sel = row;
        for (ll i = row; i < n; ++i) {
            if (abs(a[i][col]) > abs(a[sel][col])) {
                sel = i;
            }
        }

        if (abs(a[sel][col]) < EPS) {
            continue;
        }
        for (int i = col; i <= m; ++i) {
            swap(a[sel][i], a[row][i]);
        where[col] = row;

        for (int i = 0; i < n; ++i)
            if (i != row) {
                double c = a[i][col] / a[row][col];
                for (int j = col; j <= m; ++j)
                    a[i][j] -= a[row][j] * c;
            }
        ++row;
    }

    ans.assign(m, 0);
    for (int i = 0; i < m; ++i)
        if (where[i] != -1)
            ans[i] = a[where[i]][m] / a[where[i]][i];
    for (int i = 0; i < n; ++i) {
        double sum = 0;
        for (int j = 0; j < m; ++j)
            sum += ans[j] * a[i][j];
        if (abs(sum - a[i][m]) > EPS)
            return 0;
    }

    for (int i = 0; i < m; ++i)
        if (where[i] == -1)
            return oo;
    return 1;
}

int main() {
//    freopen("/Users/milenkoviclazar/sandbox/competitive_programming/input.in", "r", stdin);
    std::ios_base::sync_with_stdio(false);
    while (!cin.eof()) {
        long long a, b, x, y;
        cin >> a >> b;
        if (cin.eof()) {
            break;
        }
        long long d = extended_euclidean(a, b, x, y);
        cout << x << " " << y << " " << d << endl;
    }


    return 0;
}
