#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> prefixFunction(const string &p) {
    vector<int> pi(p.length() + 1, -1);
    int k = -1;
    for (int q = 1; q < p.length(); q++) {
        while (k != -1 && p[k + 1] != p[q]) {
            k = pi[k];
        }
        if (p[k + 1] == p[q]) {
            k++;
        }
        pi[q] = k;
    }
    return pi;
}

vector<int> kmp(const string &t, const string &p) {
    vector<int> pi = prefixFunction(p);
    vector<int> ret;
    int q = -1;
    for (int i = 0; i < t.length(); i++) {
        while (q != -1 && p[q + 1] != t[i]) {
            q = pi[q];
        }
        if (p[q + 1] == t[i]) {
            q++;
        }
        if (q + 1 == p.length()) {
            ret.push_back(i - q);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    int tsts;
    cin >> tsts;
    while (tsts--) {
        string t, p;
        cin >> t >> p;
        auto ret = kmp(t, p);
        if (ret.empty()) {
            cout << "Not Found" << endl << endl;
            continue;
        }
        cout << ret.size() << endl;
        for (auto x : ret) {
            cout << x + 1 << " ";
        }
        cout << endl << endl;
    }
    return 0;
}

