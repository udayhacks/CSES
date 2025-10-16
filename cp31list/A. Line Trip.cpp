#include <bits/stdc++.h>
using namespace std ; 
// time = 2 sec ; 
// 

int main(){

	int t; // t<= 1000;
	cin>>t;
	while( t--){
		int n ,x ; //n E [1 , 50 ] ; x E [2 , 100];
		cin >>n>>x;
		vector<int> a(n);
		for ( int i = 0 ;  i<n;i++) cin >> a[i];
		a.push_back(x);
		a.push_back(0);
		sort(a.begin(),a.end());
		int ans = 0 ;

		for ( int i = 1 ; i<n+2 ;i++){
			
			int val = 0 ;
			val +=(abs(a[i]-a[i-1]));
			if ( i == n+1 ){
				
				val +=val ;
			}

			
			ans = max(ans,val);
		}
		cout<<ans<<'\n';




	}

	return 0 ;
}