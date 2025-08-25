#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    vector<ll> prev(m+2,0), curr(m+2,0); // +2 to avoid boundary checks

    // Initialize first row
    if (arr[0] != 0) {
        prev[arr[0]] = 1;
    } else {
        for(int j = 1; j <= m; j++) prev[j] = 1;
    }

    for(int i = 1; i < n; i++) {
        fill(curr.begin(), curr.end(), 0); // reset current row

        for(int j = 1; j <= m; j++) {
            if(arr[i] == 0 || arr[i] == j) {
                curr[j] = (prev[j] + prev[j-1] + prev[j+1]) % MOD;
            }
        }

        prev = curr; // move current row to previous
    }

    ll total = 0;
    for(int j = 1; j <= m; j++) total = (total + prev[j]) % MOD;

    cout << total << "\n";

    return 0;
}
