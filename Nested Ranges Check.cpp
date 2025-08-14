//// CP tempalte////
#include <bits/stdc++.h>
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
#endif
}

////////////////////////////////////////////////////////////////////////////////
//                              MAIN CODE                                     //
////////////////////////////////////////////////////////////////////////////////

struct Range {
    int l, r, id;
};

int main() {
    fastio();            // enable fast I/O always
    file_out();

    int n; 
    cin >> n; 
    vector<Range> ranges(n);
    vector<int> contains(n, 0), contained(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> ranges[i].l >> ranges[i].r;
        ranges[i].id = i;
    }

    // Sort by l asc, and for equal l, by r desc
    sort(all(ranges), [](const Range &a, const Range &b){
        if (a.l == b.l) return a.r > b.r;
        return a.l < b.l;
    });

    // Pass 1: mark "contained" (left -> right)
    int max_r = -1;
    for (const auto &rg : ranges) {
        if (rg.r <= max_r) contained[rg.id] = 1;
        max_r = max(max_r, rg.r);
    }

    // Pass 2: mark "contains" (right -> left)  <-- FIXED
    int min_r = INT_MAX;
    for (int i = n - 1; i >= 0; --i) {
        if (ranges[i].r >= min_r) contains[ranges[i].id] = 1;
        min_r = min(min_r, ranges[i].r);
    }

    // Output in original input order
    for (int i = 0; i < n; i++) {
        cout << contains[i] << (i + 1 == n ? '\n' : ' ');
    }
    for (int i = 0; i < n; i++) {
        cout << contained[i] << (i + 1 == n ? '\n' : ' ');
    }
    return 0;
}

/*

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n;

void solve(vector<vector<int>> ranges) {
    vector<int> check(n + 1);

    int pos = 0;
    for (auto r : ranges) {
        if (pos >= -r[1]) {
            check[r[2]] = 1;
        }
        pos = max(pos, -r[1]);
    }

    for (int i = 1; i <= n; i++) {
        cout << check[i] << " ";
    }
    cout << "\n";
}

int main() {
    cin >> n;

    vector<vector<int>> ranges1;
    vector<vector<int>> ranges2;

    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        ranges1.push_back({y, -x, i});
        ranges2.push_back({x, -y, i});
    }

    sort(ranges1.begin(), ranges1.end());
    sort(ranges2.begin(), ranges2.end());

    solve(ranges1);
    solve(ranges2);
}












































*/