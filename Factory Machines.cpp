#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool canMake(ll time, vector<ll>& k, ll t) {
    ll products = 0;
    for (ll x : k) {
        products += time / x;
        if (products >= t) return true; // avoid overflow
    }
    
    return products >= t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll t;
    cin >> n >> t;
    vector<ll> k(n);
    for (int i = 0; i < n; i++) cin >> k[i];

    ll low = 0, high = *max_element(k.begin(), k.end()) * t;
    ll ans = high;

    while (low <= high) {
        ll mid = low + (high - low) / 2;
        if (canMake(mid, k, t)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << "\n";
    return 0;
}
