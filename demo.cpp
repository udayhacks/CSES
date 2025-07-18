
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




int mem(int i ,int k ,vector<int> arr,vector<int> st){
    if (i == 0 ) {
        if(st[i] == 1 || st[i]==0 && k >0 ) return arr[i];
        return 0;
    }

    int pick = 0;
    int not_pick = 0 ;



     if(st[i] == 1 || st[i]==0 && k >0 ) {
        if (st[i]== 0 ) k--;
        pick = arr[i]+mem(i-1,k,arr,st);
     }
     not_pick = mem(i-1,k,arr,st);
     return max(pick,not_pick); 






}


int main() {
    file_out();

    //  int  n = 3;
    // vector<string> passwords = {"password1", "password1", "password1"};
    //     int k = 2;

    //     map<string,int> track;

    //     for (string &i : passwords){
    //         if (track[i]<k) {
    //             track[i]++;

    //             cout<<"ACCEPT\n";
    //         }
    //         else{
    //             cout<<"REJECT\n";
    //         }
    //     }
    //     if (track.find("password0") != track.end())  cout<<"ACCEPT value\n";


    vector<int> arr {7,4,3,5};
    vector<int> sts{ 1,0,0,0};
    int k = 2;
    int ans = mem(4,k,arr,sts,);
    vector<vector<int>>dp(arr.size(),vector<int>(k,-1));
    cout<<ans;


    
return 0 ;
}
