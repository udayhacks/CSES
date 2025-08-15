
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
    fastio();
#endif
}



////////////////////////////////////////////////////////////////////////////////
//                              MAIN CODE                                     //
////////////////////////////////////////////////////////////////////////////////







int main() {
    file_out();
    /***//////////////////input space //////////////***/
    

int n , m;
cin >> n >> m;
pair<int,int> start, end;
vector<vector<char>> grid(n, vector<char>(m));
for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        cin >> grid[i][j];
        if (grid[i][j] == 'A') {
            start = {i, j};
        } else if (grid[i][j] == 'B') {
            end = {i, j};
        }
    }
}


vector<vector<bool>> visited(n, vector<bool>(m, false));
queue<pair<int, int>> q;    
int dx[] = {0,-1,0,1};
int dy [] = {-1,0,1,0};
int dr[] = {'L', 'U', 'R', 'D'}; // Directions for left, up, right, down
unordered_map <int,char>map;


q.push(start);
vector<vector<int>> path(n,vector<int>(m,5)); // To store the path directions
visited[start.first][start.second] = true;


while (!q.empty()) {
    auto [x, y] = q.front();
    q.pop();
    
    if (x == end.first && y == end.second) break;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny] != '#') {
            visited[nx][ny] = true;
            path[nx][ny] = i;// Store the direction in the path
            q.push({nx, ny});
        }
    }
    if (visited[end.first][end.second]) {
        break; // If we reached the end, no need to continue
    }
}


    
if (!visited[end.first][end.second]) cout<<"NO"<<nline;m,
else {
    cout<<"YES"<<nline;
    string ans = "";
    int x = end.first, y = end.second;

    while(make_pair(x,y) != start) {
        int dir = path[x][y];
        ans += dr[dir]; // Append the direction to the answer string
        x -= dx[dir]; // Move in the opposite direction to trace back   
        y -= dy[dir]; // Move in the opposite direction to trace back
    }
    
    reverse(ans.begin(), ans.end()); // Reverse the path to get the correct order
    cout << ans.size() << nline; // Output the length of the path
    cout << ans << nline; // Output the path
} 
 
return 0;
}