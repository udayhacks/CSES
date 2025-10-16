#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n ; 
    cin>>n; 
    vector<int> a(n);
    int ans = INT_MAX ;
    for ( int i = 0 ;i<n;i++) {
        cin >>a[i];
        ans = min(ans,abs(a[i]));
    }
    cout<<ans<<endl;



    
}
