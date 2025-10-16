#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; 
    cin >> t;
    while (t--) {
        int n; 
        cin >> n;
        vector<int> a(n); // ✅ Must specify size n before accessing indices
        for (int i = 0; i < n; i++) 
            cin >> a[i];

        if (n == 2) {       // ✅ continue instead of break
            cout << "YES\n";
            continue;
        }

        map<int, int> mp;
        for (int i : a)
            mp[i]++;

        if (mp.size() > 2) {
            cout << "NO\n";
            continue; // ✅ not return 0; (that would stop all test cases)
        }

        int k= n,o = n ;
        for (auto [i, j] : mp){
            o = k ;
            k = j ; 

        }

            

        if ((abs(k-o)>1)) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}
