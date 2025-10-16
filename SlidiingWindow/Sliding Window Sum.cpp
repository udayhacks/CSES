#include<iostream>
#include<vector>
#define nl '\n'

#define ll long long 
using namespace std;

int main(){

	 ll n ,k;
	cin>>n>>k;
	ll x,a,b,c;
	cin>>x>>a>>b>>c;
	vector<ll> arr;



	for ( ll i = 0;i<n;i++){
		if (i == 0) arr.push_back(x);
		else{
			ll f = (a*arr[i-1]+b)%c;
			arr.push_back(f);
		}
	}
	
	vector<ll> window_sums;
	ll l = -1 ;
	ll sum = 0;
	for ( int i = 0 ;i<n;i++){
		sum |= arr[i];
		if (l >=0){
			sum |= (~arr[l]);
		}
		if ( i-l == k){
			window_sums.push_back(sum);
			l++;
		}
		
	}
	ll ans =0;

	for ( ll i : window_sums){
		cout<<i<<" ";
	}
	cout<<endl;
	for (ll i : window_sums){
		ans^=i;
	}cout<<ans<<nl;




}