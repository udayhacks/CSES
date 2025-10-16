#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t ; // 5000 ;
    cin >>t;
    while(t--){
        int n ; // 10 ;
        cin >>n; 
        vector<int> a(n);
        for ( int i = 0 ; i<n;i++) cin >> a[i];

        
        if ( a[0] ==1) cout<<"yes"<<'\n';
        else cout<<"no"<<'\n';

    }

    
}
