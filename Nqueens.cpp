
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


//condition to check :
// placement of queen is trial and error 
// if success if row = 1 to 8 then return 1 else 0 ;
// safe fundtion check for straight line and diagonal 
// from diagonal part check for upper-left and upper -right ;
//no need for down because you did even tried their hehee....:)

bool safe(vector<vector<char>>& board, int row, int col) {
    if (board[row][col] == '*') return false;

    // Check column
    for (int i = 0; i < row; ++i)
        if (board[i][col] == 'Q') return false;

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
        if (board[i][j] == 'Q') return false;

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < 8; --i, ++j)
        if (board[i][j] == 'Q') return false;

    return true;
}

int total_queens(vector<vector<char>>&board,int row){
    int count = 0 ; 
    if (row ==8) return 1;

    for (int col = 0 ; col<8;col++){
        if (board[row][col] != '*' && safe(board, row ,col)){
            board[row][col] = 'Q';
            count+=total_queens(board,row+1);
            board[row][col] ='.';

        }
    }
    return count;


}








void solution(vector<vector<char>>&board){

    int count = total_queens(board,0);
    cout<<count<<endl;

}











int main() {
    file_out();
    vector<vector<char>>board(8,vector<char>(8));
    for (int i = 0; i<8;i++){
        for (int j = 0 ; j<8;j++){
            cin >>board[i][j];
        }
    }

/*    for (int i = 0 ; i<8;i++){
        for(int j = 0 ; j<8;j++){
            cout<<board[i][j];
        }
        cout<<endl;
    } */
    solution(board);

    
return 0 ;
}
