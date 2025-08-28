#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> h, L, R, dp;

int solve(int i) {
    if (dp[i] != -1) return dp[i];
    int res = 1;
    if (L[i] != -1) res = max(res, 1 + solve(L[i]));
    if (R[i] != -1) res = max(res, 1 + solve(R[i]));
    return dp[i] = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    h.resize(n);
    for (int i = 0; i < n; i++) cin >> h[i];

    L.assign(n, -1);
    R.assign(n, -1);

    // nearest smaller to left
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && h[st.top()] <= h[i]) st.pop();
        if (!st.empty()) L[i] = st.top();
        st.push(i);
    }

    // nearest smaller to right
    while (!st.empty()) st.pop();
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && h[st.top()] <= h[i]) st.pop();
        if (!st.empty()) R[i] = st.top();
        st.push(i);
    }

    dp.assign(n, -1);
    int ans = 0;
    for (int i = 0; i < n; i++) ans = max(ans, solve(i));
    cout << ans << "\n";
}
