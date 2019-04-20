#include <bits/stdc++.h>

using namespace std;

const int MAXN = 111;

bool adj[MAXN][MAXN];
bool adj2[MAXN][MAXN];
bool adj3[MAXN][MAXN];

int reg = 0;
int n = reg * reg + 2 * reg + 1;

void multiply(bool a[][MAXN], bool b[][MAXN], bool c[][MAXN]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] || b[i][j]) {
                c[i][j] = true;
            }

        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (c[i][j]) {
                continue;
            }
            for (int k = 0; k < n; k++) {
                if (a[i][k] && b[k][j]) {
                    c[i][j] = true;
                    break;
                }
            }
        }
    }
}

bool visited[MAXN];
int pre[MAXN];

bool hamiltonian(int curr, int lvl, bool adjacency[][MAXN]) {
    if (lvl == n - 1) {
        if (adjacency[curr][0]) {
            cout << "\nSEQ: ";
            for (int i = curr; i != 0; i = pre[i]) {
                cout << i << " ";
            }
            cout << endl;
            return true;
        }
        return false;
    }
    visited[curr] = true;
    for (int i = 0; i < n; i++) {
//        cout << "I: " << i << endl;
        if (visited[i]) {
            continue;
        }
        if (!adjacency[curr][i]) {
            continue;
        }
        pre[i] = curr;
        if (hamiltonian(i, lvl + 1, adjacency)) {
            return true;
        }
    }
    visited[curr] = false;
    return false;
}

int main() {
    freopen("/Users/milenkoviclazar/sandbox/competitive_programming/input.in", "r", stdin);
//    n = 15;
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            adj[i][j] = true;
//        }
//    }
//    memset(visited, false, sizeof visited);
//    cout << (hamiltonian(0, 0, adj) ? "YES" : "NO") << endl;
//    return 0;

//    n = 4;
//    adj[0][1] = adj[1][0] = true;
//    adj[2][3] = adj[3][2] = true;
//    adj[3][1] = adj[2][0] = true;
//    adj[0][3] = adj[1][2] = true;
    cin >> n >> reg;
    assert(n = reg * reg + 2 * reg + 1);
    for (int i = 1; i < n; i += reg + 2) {
        adj[0][i] = true;
        adj[i][0] = true;
    }
    for (int i = 1; i <= reg + 2; i++) {
        for (int j = 0; j < reg; j++) {
            int x;
            cin >> x;
            adj[i][x] = true;
            if (x == 0) {
                continue;
            }
            for (int add = reg + 2; i + add < n; add += reg + 2) {
                adj[i + add][x + add] = true;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        for (int j = 0; j < n; j++) {
            if (adj[i][j]) {
                cout << j << " ";
            }
        }
        cout << endl;
    }
    memset(visited, false, sizeof visited);
    cout << (hamiltonian(0, 0, adj) ? "YES" : "NO") << endl;

    multiply(adj, adj, adj2);
    memset(visited, false, sizeof visited);
//    for (int i = 0; i < n; i++) {
//        cout << i << ": ";
//        for (int j = 0; j < n; j++) {
//            if (adj2[i][j]) {
//                cout << j << " ";
//            }
//        }
//        cout << endl;
//    }
    cout << (hamiltonian(0, 0, adj2) ? "YES" : "NO") << endl;

    multiply(adj2, adj, adj3);
    memset(visited, false, sizeof visited);

    cout << (hamiltonian(0, 0, adj3) ? "YES" : "NO") << endl;
    return 0;
}
