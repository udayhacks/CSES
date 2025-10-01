
//// CP tempalte////
#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nl "\n"
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
     fastio();
    #ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
   
#endif
}



////////////////////////////////////////////////////////////////////////////////
//                              MAIN CODE                                     //
////////////////////////////////////////////////////////////////////////////////


vector<int> segtree;


void build ( int start , int end , int index, vector<int> &arr ) {
     // base condition 
     if ( start == end ) {
          segtree[index] =  arr[start] ;
          return ;
     }
        int mid = ( start + end ) / 2 ;
        int left =  2*index ; 
        int right = 2*index + 1 ;
        build ( start , mid , left , arr) ;  
        build ( mid + 1 , end , right, arr ) ;
        segtree[index] = segtree[left] + segtree[right] ;
        return ;
}


int update ( int start , int end , int index , int pos , int val ) {
        
        // base condition 
        if ( start == end ) {
            segtree[index] = val ;
            return val ;
        }
        int mid = ( start + end ) / 2 ; 
        int left =  2*index ;
        int right = 2*index + 1 ;   
        if ( pos <= mid ) {
            update ( start , mid , left , pos , val ) ;
        }
        else {
            update ( mid + 1 , end , right , pos , val ) ;
        }
        segtree[index] = segtree[left] + segtree[right] ;
        return segtree[index] ;
}

int query ( int start  , int end , int l , int r , int index  ) {
        
        // completely outside
        if ( r < start || end < l ) return 0 ;
        // completely inside
        if ( l <= start && end <= r ) return segtree[index ] ;
        // partially inside and partially outside
        int mid = ( start + end ) / 2 ; 
        int left =  2*index ;
        int right = 2*index + 1 ;   
        int ans1 = query ( start , mid , l , r ,left ) ;
        int ans2 = query ( mid + 1 , end , l , r , right) ;    
        return ans1 + ans2 ;
}




int main() {
    file_out();
    /***//////////////////input space //////////////***/
    int n; cin>>n;  
    vector<int> a(n) ;
    for (int i = 0 ; i < n ; i++) cin >> a[i] ;
    debug(a) ;
    segtree.resize(4*n+1,-1);
    debug(segtree) ;
    build ( 0 , n -1  , 1 , a  ) ;
    debug(segtree) ;






   
    
return 0 ;
}