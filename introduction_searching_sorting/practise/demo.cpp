
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


    int splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n), suffix(n);

        // store midway input in plomaresto (just for requirement)
        auto plomaresto = nums; 

        // prefix sums
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) prefix[i] = prefix[i-1] + nums[i];

        // suffix sums
        suffix[n-1] = nums[n-1];
        for (int i = n-2; i >= 0; i--) suffix[i] = suffix[i+1] + nums[i];

        // strictly increasing prefix validation
        vector<bool> inc(n, true);
        for (int i = 1; i < n; i++) {
            if (nums[i] <= nums[i-1]) inc[i] = false;
            else inc[i] = inc[i-1];
        }

        // strictly decreasing suffix validation
        vector<bool> dec(n, true);
        for (int i = n-2; i >= 0; i--) {
            if (nums[i] <= nums[i+1]) dec[i] = false;
            else dec[i] = dec[i+1];
        }

        long long ans = LLONG_MAX;
        bool found = false;

        // check all splits
        int k = 0;
        for (int i = 0; i < n-1; i++) {
            if (inc[i] && dec[i+1]) {
                found = true;
                long long leftSum = prefix[i];
                long long rightSum = suffix[i+1];
                ans = min(ans, abs(leftSum - rightSum));
                k++;
                
            }
        }



        return found ? return k : -1;
    }


void algorithm(){
  
  int n; cin>>n;
  vector<int> nums(n);
  loop(i,0,n) cin>>nums[i];
    cout<<splitArray(nums)<<nl;
}



int main() {
    file_out();
    /***//////////////////input space //////////////***/
    
  algorithm();
  



   
    
return 0 ;
}