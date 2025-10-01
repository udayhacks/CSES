#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define nl "\n"

typedef long long ll;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" == "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(int t) {cerr << t;}

void file_out(){
    fastio();
    #ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
    #endif
}

void algorithm(){
    int n, m;
    cin >> n >> m;
    vector<string> board(n);
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }

    queue<pair<int,int>> que;
    pair<int,int> start;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'M') {
                que.push({i,j});
            }
            if (board[i][j] == 'A') {
                start = {i,j};
            }
        }
    }

    auto check = [&](int i, int j) {
        return (i >= 0 && j >= 0 && i < n && j < m && board[i][j] == '.');
    };

    que.push(start);
    while (!que.empty()) {
        auto [i,j] = que.front(); que.pop();
        debug(i);
        debug(j);

        if (check(i, j+1)) { board[i][j+1] = (board[i][j]=='M') ? 'M' : 'R'; que.push({i,j+1}); }
        if (check(i, j-1)) { board[i][j-1] = (board[i][j]=='M') ? 'M' : 'L'; que.push({i,j-1}); }
        if (check(i-1, j)) { board[i-1][j] = (board[i][j]=='M') ? 'M' : 'U'; que.push({i-1,j}); }
        if (check(i+1, j)) { board[i+1][j] = (board[i][j]=='M') ? 'M' : 'D'; que.push({i+1,j}); }
    }

  
    pair<int,int> ans;
    ans.first = -1;
    ans.second = -1;

    for ( int i = 0; i<n;i++){
        for(int j = 0 ;j<m;j++){
            if ( i == 0 || j ==0 || j==m-1|| i == n-1){
                if (board[i][j] == 'R' || board[i][j] == 'L' || board[i][j] == 'D' || board[i][j] == 'U' || board[i][j] == 'A'){
                ans.first = i ;
                ans.second = j;
                break;
                }
            }
        }
    }
    if ( ans.first == -1 || ans.second == -1){
    cout<<"NO"<<nl;
    return;
}

   auto [i , j] = ans;
vector<char> path;

while (board[i][j] != 'A') {
    char dir = board[i][j];
    path.push_back(dir);

    if (dir == 'D') i--; // reverse move
    if (dir == 'U') i++; // reverse move
    if (dir == 'R') j--; // reverse move
    if (dir == 'L') j++; // reverse move
}
//path.push_back(board[i][j]);


reverse(path.begin(), path.end()); // because we traced backward
cout<<"YES"<<nl;
cout << path.size() << nl;
for (auto c : path) cout << c;
cout << nl;


}

int main() {
    file_out();
    algorithm();
    return 0;
}
