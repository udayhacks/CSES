
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





struct segment_tree {
    vector<ll> segtree;
    int n;
    segment_tree(int n) {
        this->n = n;
        segtree.assign(4 * n, 0);
    }

    void update(int start, int end, int index, int pos, ll val) {
        if (start == end) {
            segtree[index] = (segtree[index] + val) % MOD;
            return;
        }
        int mid = (start + end) / 2;
        if (pos <= mid) update(start, mid, 2 * index, pos, val);
        else update(mid + 1, end, 2 * index + 1, pos, val);
        segtree[index] = (segtree[2 * index] + segtree[2 * index + 1]) % MOD;
    }

    ll query(int start, int end, int l, int r, int index) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return segtree[index];
        int mid = (start + end) / 2;
        return (query(start, mid, l, r, 2 * index) +
                query(mid + 1, end, l, r, 2 * index + 1)) % MOD;
    }

    void update(int pos, ll val) {
        update(1, n, 1, pos, val);
    }

    ll query(int l, int r) {
        if (l > r) return 0;
        return query(1, n, l, r, 1);
    }
};

void algorithm() {
    int n; cin >> n;
    vector<ll> arr(n), b(n);
    loop(i, 0, n) cin >> arr[i];
    b = arr;
    sort(all(b));
    b.erase(unique(all(b)), b.end());

    auto get_id = [&](ll x) {
        return (int)(lower_bound(all(b), x) - b.begin() + 1);
    };

    segment_tree seg(sz(b));
    ll ans = 0;

    for (ll x : arr) {
        int id = get_id(x);
        ll cnt = (1 + seg.query(1, id - 1)) % MOD;
        seg.update(id, cnt);
        ans = (ans + cnt) % MOD;
    }

    cout << ans % MOD << nl;
}


int main() {
    file_out();
    /***//////////////////input space //////////////***/
    
  algorithm();
  



   
    
return 0 ;
}