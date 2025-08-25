//// CP template ////
#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
typedef long long ll;

bool safeB(int r , int c, int n, vector<vector<char>>& grid) {
    if (r < n && r >= 0 && c < n && c >= 0) {
        return (grid[r][c] != '*');
    }
    return false;
}

ll f(int r, int c, int n, vector<vector<char>>& grid, vector<vector<ll>> &dp) {
    if (!safeB(r,c,n,grid)) return 0; // trap or out of bounds
    if (r == 0 && c == 0) return 1;   // reached start
    if (dp[r][c] != -1) return dp[r][c];

    ll val = 0;
    // move left
    if (safeB(r, c-1, n, grid)) val = (val + f(r, c-1, n, grid, dp)) % MOD;
    // move up
    if (safeB(r-1, c, n, grid)) val = (val + f(r-1, c, n, grid, dp)) % MOD;

    return dp[r][c] = val;
}

int main() {
    fastio();
    int n; 
    cin >> n;

    /*
        vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<ll>> dp(n, vector<ll>(n, -1));
    //cout << f(n-1, n-1, n, grid, dp) % MOD << "\n";
    
    
    */
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    vector<vector<int>> paths(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '*') {
                paths[i][j] = 0;
            } else {
                paths[i][j] = i == 0 && j == 0;
                if (i) paths[i][j] += paths[i - 1][j];
                if (j) paths[i][j] += paths[i][j - 1];
                paths[i][j] %= MOD;
            }
        }
    }

    cout << paths[n - 1][n - 1] << "\n";

    return 0;
}
