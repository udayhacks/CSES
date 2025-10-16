#include<iostream>
#include<vector>
#include<deque>
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
	
	vector<ll> window_min;

	ll l = -1 ;
	deque<ll> dq;
	
	for ( int i = 0 ;i<n;i++){
		
		if(!dq.empty() && dq.front() == i-k){
			dq.pop_front();
		}

		while(!dq.empty() && arr[dq.back()] >arr[i]){
			dq.pop_back();
		}
		dq.push_back(i);
		if (i>=k-1){
			window_min.push_back(arr[dq.front()]);
			
		}
	}


	ll ans =0;
	for (ll i : window_min){
		ans^=i;
	}cout<<ans<<nl;




}