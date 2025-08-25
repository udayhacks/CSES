//// CP template ////
#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long ll;

bool canDivide(vector<ll>& arr, ll k, ll maxSum) {
    ll currSum = 0, parts = 1; 
    for (ll x : arr) {
        if (currSum + x > maxSum) {
            parts++;
            currSum = x;
            if (parts > k) return false;
        } else {
            currSum += x;
        }
    }
    return true;
}

int main() {
    fastio();
    int n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    ll lo = 0, hi = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        lo = max(lo, arr[i]);
        hi += arr[i];
    }

    ll ans = hi;
    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;
        if (canDivide(arr, k, mid)) {
            ans = mid;
            hi = mid - 1; // try smaller maximum
        } else {
            lo = mid + 1; // need larger maximum
        }
    }

    cout << ans << "\n";
    return 0;
}
