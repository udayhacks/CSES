#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
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
#define debug(x) cerr << #x << " == "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

template <typename T> void _print(T arr[], size_t n) { cerr << "["; loop(i, 0, n) cerr << arr[i] << " "; cerr << "]\n"; }
template <class T, class V> void _print(pair<T, V> p);
template <class T> void _print(vector<T> v);
template <class T> void _print(set<T> v);
template <class T, class V> void _print(map<T, V> v);
template <class T> void _print(multiset<T> v);
template <class T, class V> void _print(pair<T, V> p) { cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}\n"; }
template <class T> void _print(vector<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]\n"; }
template <class T> void _print(set<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]\n"; }
template <class T> void _print(multiset<T> v) { cerr << "[ "; for (T i : v) { _print(i); cerr << " "; } cerr << "]\n"; }
template <class T, class V> void _print(map<T, V> v) { cerr << "[ "; for (auto i : v) { _print(i); cerr << " "; } cerr << "]\n"; }

void file_out() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
}

// ------------------------------------------------------------------------
// ---------------------------- MAIN CODE ---------------------------------
// ------------------------------------------------------------------------

void generator(vector<vector<char>> &arr, vector<vector<char>> &newArr, int n, int m) {
    int dr[2] = {0, -1};
    int dc[2] = {-1, 0};
    string s = "ABCD";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bool used[256] = {false};
            used[arr[i][j]] = true; // original char

            for (int k = 0; k < 2; k++) {
                int ni = i + dr[k];
                int nj = j + dc[k];
                if (ni >= 0 && nj >= 0) {
                    used[newArr[ni][nj]] = true;
                }
            }

            for (char c : s) {
                if (!used[c]) {
                    newArr[i][j] = c;
                    break;
                }
            }
        }
    }
}

void solution(int n, int m, vector<vector<char>> &arr) {
    vector<vector<char>> newArr(n, vector<char>(m));
    generator(arr, newArr, n, m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << newArr[i][j];
        }
        cout << "\n";
    }
}

int main() {
    file_out();
    int n, m;
    cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    solution(n, m, arr);

    return 0;
}
