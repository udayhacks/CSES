//// CP template ////
#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef long long ll;

////////////////////////////////////////////////////////////////////////////////
//                          RECURSION + MEMO                                  //
////////////////////////////////////////////////////////////////////////////////
int f(int i , int budget, int x, vector<int>& prices, vector<int>& pages, vector<vector<int>>& dp) {
    if (i == 0) {
        if (prices[0] <= budget) return pages[0];
        return 0;
    }
    if (dp[i][budget] != -1) return dp[i][budget];

    int notpick = f(i-1, budget, x, prices, pages, dp);
    int pick = 0;
    if (prices[i] <= budget) pick = pages[i] + f(i-1, budget - prices[i], x, prices, pages, dp);

    return dp[i][budget] = max(pick, notpick);
}

////////////////////////////////////////////////////////////////////////////////
//                                  MAIN                                      //
////////////////////////////////////////////////////////////////////////////////
int main() {
    fastio();

    int n, x; 
    cin >> n >> x;
    vector<int> prices(n), pages(n);

    for (int i = 0; i < n; i++) cin >> prices[i];
    for (int i = 0; i < n; i++) cin >> pages[i];

    /////////////////////// Tabulation ///////////////////////
    vector<vector<int>> dp(n, vector<int>(x+1, 0));

    // Base case: first book
    for (int j = 0; j <= x; j++) {
        if (prices[0] <= j) dp[0][j] = pages[0];
    }

    // Fill DP table
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= x; j++) {
            int notpick = dp[i-1][j];
            int pick = 0;
            if (prices[i] <= j) pick = pages[i] + dp[i-1][j - prices[i]];
            dp[i][j] = max(pick, notpick);
        }
    }

    cout << dp[n-1][x] << "\n";

    /////////////////////// Recursion + Memo (optional) ///////////////////////
    /*
    vector<vector<int>> memo(n, vector<int>(x+1, -1));
    cout << f(n-1, x, x, prices, pages, memo) << "\n";
    */
    return 0;
}
