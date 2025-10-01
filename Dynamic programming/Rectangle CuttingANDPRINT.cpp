//// CP template ////
#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

struct Cut {
    char type; // 'H' or 'V' or 'N'
    int index;
};

int main() {
    fastio();
    int a, b;
    if (!(cin >> a >> b)) return 0;

    const int INF = 1e9;
    vector<vector<int>> dp(a+1, vector<int>(b+1, INF));
    vector<vector<Cut>> parent(a+1, vector<Cut>(b+1, {'N', -1}));

    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
            if (i == j) {
                dp[i][j] = 0;
                parent[i][j] = {'N', -1};
                continue;
            }
            // horizontal cuts: split into k x j and (i-k) x j, with 1 <= k <= i-1
            for (int k = 1; k < i; ++k) {
                int cand = dp[k][j] + dp[i-k][j] + 1;
                if (cand < dp[i][j]) {
                    dp[i][j] = cand;
                    parent[i][j] = {'H', k};
                }
            }
            // vertical cuts: split into i x k and i x (j-k), with 1 <= k <= j-1
            for (int k = 1; k < j; ++k) {
                int cand = dp[i][k] + dp[i][j-k] + 1;
                if (cand < dp[i][j]) {
                    dp[i][j] = cand;
                    parent[i][j] = {'V', k};
                }
            }
        }
    }

    cout << dp[a][b] << "\n";

    // Reconstruct and print cuts (preorder)
    function<void(int,int)> reconstruct = [&](int h, int w) {
        if (h == w) return;
        Cut c = parent[h][w];
        if (c.type == 'H') {
            cout << "Cut (" << h << "x" << w << ") horizontally at height " << c.index << "\n";
            reconstruct(c.index, w);
            reconstruct(h - c.index, w);
        } else if (c.type == 'V') {
            cout << "Cut (" << h << "x" << w << ") vertically at width " << c.index << "\n";
            reconstruct(h, c.index);
            reconstruct(h, w - c.index);
        }
    };

    reconstruct(a, b);
    return 0;
}
