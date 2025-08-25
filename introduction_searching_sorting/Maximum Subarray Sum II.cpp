
//// CP tempalte////
#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define loop(i, a, b) for (int i = a; i < b; i++)

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" == "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template<typename T> void _print(T arr[],size_t n) {  cerr <<'[' ;loop(i, 0, n) cerr << arr[i] << " ";cerr<<']'<<"\n";}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}"<<'\n';}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]"<<'\n';}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]"<<'\n';}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]"<<'\n';}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]"<<'\n';}
void file_out(){
    #ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
    fastio();
#endif
}



////////////////////////////////////////////////////////////////////////////////
//                              MAIN CODE                                     //
////////////////////////////////////////////////////////////////////////////////
/*
///solution doc
// subarray sum deal with prefixsum  pref

when  i = r ; 
length of subarr = r-l+1;
sum(l,r ) = pref[r+1] - pref[l], generally 
required a<=r-l+1<=b
here l must be mini
l =[r-b+1,r-a+1]; in arrays 
l = [r-b,r-a]  in pref where pref[i] = sum of ar[0 to  i-1];


*/

/*
#include <iostream>
#include <set>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    vector<ll> sums;
    sums.push_back(0);
    multiset<ll> order;

    ll sum = 0;
    ll answer = -1e18;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        sum += x;
        sums.push_back(sum);

        if (i >= a) {
            order.insert(sums[i - a]);
            answer = max(answer, sum - *order.begin());
        }

        if (i >= b) {
            order.erase(order.find(sums[i - b]));
        }
    }

    cout << answer << "\n";
}
*/





int main() {
    file_out();
    /***//////////////////input space //////////////***/
    int a ,b,n;
    cin >> n>> a>>b;
    vector<ll> arr(n);

    for(int i = 0;i<n;i++) cin>>arr[i];

    vector<ll> prefix(n+1,0);
    prefix[0] = arr[0];
    for(int i = 0;i<n;i++){
        prefix[i+1] = prefix[i]+arr[i];
    }

    //for(ll &i :prefix) cout<<i<<" ";
    multiset<ll> st;
    ll ans = -LLONG_MAX;

    for(int r = a;r<=n;r++){

        st.insert(prefix[r-a]);
        // r-a is the minimum value from range r-b to r-a 
      if (r-b-1 >= 0) {
    auto it = st.find(prefix[r-b-1]);
    if (it != st.end()) st.erase(it);
}

        ans = max(ans,(prefix[r]-*st.begin()));
        // pref[r] - mins(pref{L}) where L = [r-b,r-a];
    }
    cout<<ans<<endl;




   
    
return 0 ;
}