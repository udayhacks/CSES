
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
#endif
}







///////////////////////////////////////////////////////////////////////////////////        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   ////////////////////////////////////////////////////////////////////////////////MAIN CODE/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////               ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




void algorithm(const string &s) {
    bool visited[7][7] = {};
    int dx[4] = {-1, 1, 0, 0};       // U, D, L, R
    int dy[4] = {0, 0, -1, 1};
    char dir[4] = {'U', 'D', 'L', 'R'};
    ll result = 0;

    function<bool(int, int)> isvalid = [&](int x, int y) {
        return x >= 0 && x < 7 && y >= 0 && y < 7 && !visited[x][y];
    };

    function<void(int, int, int)> dfs = [&](int x, int y, int step) {
    if (x == 6 && y == 0) {
        if (step == 48) result++;
        return;
    }

    if (step >= 48) return;

    visited[x][y] = true;

    // Early return if surrounded or trapped
   if ((x > 0 && x < 6 && visited[x-1][y] && visited[x+1][y] && !visited[x][y-1] && !visited[x][y+1]) ||
        (y > 0 && y < 6 && visited[x][y-1] && visited[x][y+1] && !visited[x-1][y] && !visited[x+1][y]) ||
        (x == 0 && y == 0 && !visited[0][1] && !visited[1][0]) ||
        (x == 0 && y == 6 && !visited[0][5] && !visited[1][6]) ||
        (x == 6 && y == 0 && step != 48) ||
        (x == 6 && y == 6 && !visited[5][6] && !visited[6][5])) {
        visited[x][y] = false;
        return;
    }

    char c = s[step];
    for (int i = 0; i < 4; i++) {
        if (c != '?' && c != dir[i]) continue;
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isvalid(nx, ny)) {
            dfs(nx, ny, step + 1);
        }
    }

    visited[x][y] = false;
};

    dfs(0, 0, 0);
    cout << result << endl;
}



int main() {
    file_out();
    string s;
    cin>>s;
    algorithm(s);

    
return 0 ;
}
