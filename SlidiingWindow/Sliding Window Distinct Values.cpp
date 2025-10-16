#include <iostream>
#include<vector> 
#include<map>
using namespace std;

int main(){


	int n ,k ; 
	cin>>n>>k;
	vector<int> arr(n);
	for ( int i = 0 ;i<n;i++) cin >>arr[i];

	map <int,int>mp ;
	vector<int> ans;
	int l = -1; 
	for ( int i = 0 ;i<n;i++){


		if ( l>=0){
			if (mp.count(arr[l])){
				mp[arr[l]]--;
				if (mp[arr[l]] == 0 ) mp.erase(arr[l]);
			}
		}
		mp[arr[i]] +=1;


		if (i-l == k){
			ans.push_back(mp.size());
			l++;
		}
	}


	for( int i : ans){
		cout<<i<<" ";
	}cout<<endl;
}