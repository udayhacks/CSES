//// CP template ////
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

template<typename T> void _print(T arr[],size_t n) { cerr <<'['; loop(i, 0, n) cerr << arr[i] << " "; cerr <<']'<<"\n";}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}"; }
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]"; }
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]"; }
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]"; }
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]"; }

void file_out(){
    #ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
    fastio();
    #endif
}

////////////////////////////////////////////////////////////////////////////////
//                              MAIN CODE                                     //
////////////////////////////////////////////////////////////////////////////////

void solution(int n){
    vector<int> soliders;
    for (int i = 1; i <= n; i++) {
        soliders.push_back(i);
    }
    while(soliders.size() > 1) {
        vector<int> temp;
        for (int i = 0; i < (int)soliders.size(); i++) {
            if (i % 2 == 0) {
                temp.push_back(soliders[i]);
            }
            else {
                cout << soliders[i] << " ";
            }
        }
        if (soliders.size() % 2 == 0) soliders = temp;
        else{
            int last = temp.back();
            temp.pop_back();
            soliders.clear();
            soliders.push_back(last);
            for (int i = 0; i < temp.size(); i++) {
                soliders.push_back(temp[i]);
            }
        }
        
    }cout << soliders[0] << endl;

}







void analy(int n) {
    vector<int> soliders;
    for (int i = 1; i <= n; i++) {
        soliders.push_back(i);
    }

    for(int i = 0 ;i<soliders.size();i++){
        if(i % 2 == 1) {
            cout << soliders[i] << " ";
        }
        else{
            soliders.push_back(soliders[i]);
        }
}
}

int main() {
    file_out();
    int n;
    cin >> n;
    analy(n);
    return 0;
}
