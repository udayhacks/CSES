#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int LOG = 30;

int up[MAXN][LOG]; // up[i][k] = node reached from i after 2^k steps

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> up[i][0]; // direct teleport
    }

    // Preprocess binary lifting
    for (int k = 1; k < LOG; k++) {
        for (int i = 1; i <= n; i++) {
            up[i][k] = up[up[i][k - 1]][k - 1];
        }
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        int steps = 0;
        bool found = false;
        for (int k = LOG - 1; k >= 0; k--) {
            if (up[a][k] != 0 && up[a][k] != b) {
                a = up[a][k];
                steps += (1 << k);
            } else if (up[a][k] == b) {
                a = up[a][k];
                steps += (1 << k);
                found = true;
                break;
            }
        }
        if (a == b) {
            cout << steps << '\n';
        } else if (found) {
            cout << steps << '\n';
        } else {
            cout << -1 << '\n';
        }
    }

    return 0;
}