
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







int main() {
    file_out();
    /***//////////////////input space //////////////***/
    
    int n ; 
    cin>>n ; 
    vector<ll> arr(n);
    for (int i =0 ; i<n; i++) cin >>arr[i];
    ll total = accumulate(arr.begin(),arr.end(),0ll);
    _print(total);    

    // dp[l][r] = l is start  and r end  total = max(first -second) ; first+second = total ; 
   vector<vector<ll>> dp(n, vector<ll>(n, 0));


//base case if l == r : arr[l 'or' r]; 
for (int i = 0;i<n;i++) dp[i][i] = arr[i]; // diagonal part;

// increasing subarray and recursion relations ; 


for(int len = 2 ;len<=n;len++){
    // len 2 to n
    // because n ==1 is base condition dude; 
    for(int l = 0 ; l+len-1<n;l++){
        
        int r  = l+len-1;
        // recursion relation is :::
        // if req is cur or opp is cur trying all possi;
        int req = arr[l]- dp[l+1][r];
        int opp = arr[r] -dp[l][r-1];
        dp[l][r] = max(req , opp);

    }
}
// dp = first -second ; 
    //total = first+second;
    //first = (total+dp)/2;
    ll first = (total+dp[0][n-1])/2;
    cout<<first<<endl;


    
return 0 ;
}