
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



////////////////////////////////////////////////////////////////////////////////
//                              MAIN CODE                                     //
////////////////////////////////////////////////////////////////////////////////




void solution(multiset<int> & ms){

    // printing all elements;
    for (auto  val: ms ){
        cout<<val<<' ';
    }
    cout<<endl;

    // insert value == ms.insert()  in logn time 
    ms.insert(10);
    // delete value  in logn time 
    //erase all occurence of elements  if x == val ;
    // if x = *iterator val only *it 
    ms.erase(10);
    auto  it = ms.find(3);
    // if exit return val else .end();
    cout<<*it<< endl;


    // (lower bound  >= x  > upper bound )  
    // first element from right and left from the number line 


    auto low_bound = ms.lower_bound(7);
    // lower_bound  used for check element exist or if not exist then next greatest  element to find 
    auto up_bound = ms.upper_bound(7);
    // upper_bound is used for find next greatest element 
    cout <<*low_bound <<" and "<<*up_bound<<endl;

    //generall method like empty and size  rest ; 
    //lazy;


}





int main() {
    file_out();
    /***//////////////////input space //////////////***/
        int n ; 
        cin>>n;
        multiset<int> ms;
        // bst tree used for storing 
        //the automatically sorted elements and allows duplicates
        // un likes sets 
        for (int i = 0; i<n;i++){
            int val ; 
            cin >>val ;
            ms.insert(val);
        }




    solution(ms);

    
return 0 ;
}