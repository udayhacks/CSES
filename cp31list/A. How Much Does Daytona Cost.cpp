#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t ; 
    cin>>t; 
    while (t--){
        int n ,k;
        cin >>n>>k ;
        vector<int> a(n);
        int flag = false;
        for ( int i = 0 ; i<n;i++) {
            cin>>a[i];
            if (a[i] == k ) flag = true;
        }
        if (flag ) cout<<"Yes\n";
        else cout<< "No\n";

    }


    
}
