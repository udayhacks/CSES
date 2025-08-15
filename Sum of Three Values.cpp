//// CP tempalte////
#include <bits/stdc++.h>
using namespace std;
 
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define nline "\n"
typedef long long ll;
 
int main() {
    fastio();
 
    int n;
    ll m;
    if (!(cin >> n >> m)) return 0;
 
    vector<pair<ll,int>> a(n); // {value, original_index(1-based later)}
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        a[i] = {x, i + 1};
    }
 
    sort(a.begin(), a.end()); // sort by value
 
    for (int i = 0; i < n; i++) {
        int l = i + 1, r = n - 1;
        while (l < r) {
            ll sum = a[i].first + a[l].first + a[r].first;
            if (sum == m) {
                // output original indices in any order (or sorted if you prefer)
                cout << a[i].second << " " << a[l].second << " " << a[r].second << nline;
                return 0;
            } else if (sum < m) {
                ++l;
            } else {
                --r;
            }
        }
    }
 
    cout << "IMPOSSIBLE" << nline;
    return 0;
}