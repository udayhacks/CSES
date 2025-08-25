
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
    string s ,l; 
    cin>> s;
    cin>> l;



    
    // dp[i][j] is number of min operation till i and j length elements
    int m = l.size();
    int n = s.size();


    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    
    // base case :
    // if i<0 : j+1;
    // if j<0 : i+1;
    // here negative index not possible so shit each by one to handle this prblm;


    for(int i = 0;i<=n;i++) dp[i][0] = i ;
    for(int j = 0;j<=m;j++) dp[0][j] = j ; 



    // transition of dp:

    for(int i = 1;i<=n;i++){
        for (int j = 1;j<=m;j++){

            if (s[i-1] == l[j-1] )  dp[i][j] = dp[i-1][j-1];
              else dp[i][j] = 1+min(dp[i-1][j-1],min(dp[i-1][j] , dp[i][j-1]));
        }
    }
    cout<<dp[n][m]<<endl;

    

    





   
    
return 0 ;
}