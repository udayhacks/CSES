#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    // parent direction: -1 = none, 0 = from top, 1 = from left
    vector<vector<int>> parent(n, vector<int>(n, -1));
    vector<vector<bool>> vis(n, vector<bool>(n, false));

    // BFS frontier: cells reachable at current step
    vector<pair<int,int>> frontier;
    frontier.push_back({0,0});
    vis[0][0] = true;

    string result;
    result.push_back(grid[0][0]);




    // solution  - start from
    /*
    declare visted arr : this prevent revisit;
    declare path  : store path came from ; 
     step 1: find best char; 
     step 2: remove duplicates;
     step 3: path marking ; 
     step 4 : mark visited ; 
     step 5 : copy next to froniter
     step 6: print bestchar ; 
     step 7 : goto step 1 till i = 2n-1
    */

    for (int step = 1; step < 2*n-1; step++) {
        // collect next cells
        vector<pair<int,int>> next;
        char bestChar = 'Z' + 1;

        for (auto [x,y] : frontier) {
            // move down
            if (x+1 < n) {
                char c = grid[x+1][y];
                if (c < bestChar) {
                    bestChar = c;
                    next.clear();
                    next.push_back({x+1,y});
                } else if (c == bestChar) {
                    next.push_back({x+1,y});
                }
            }
            // move right
            if (y+1 < n) {
                char c = grid[x][y+1];
                if (c < bestChar) {
                    bestChar = c;
                    next.clear();
                    next.push_back({x,y+1});
                } else if (c == bestChar) {
                    next.push_back({x,y+1});
                }
            }
        }

        // remove duplicates
        sort(next.begin(), next.end());
        next.erase(unique(next.begin(), next.end()), next.end());

        // mark parents for backtracking
        for (auto [nx,ny] : next) {
            // if condition check where it came from from right then mark left this cell via.
            if (nx > 0 && vis[nx-1][ny] && grid[nx][ny] == bestChar) parent[nx][ny] = 0;
            if (ny > 0 && vis[nx][ny-1] && grid[nx][ny] == bestChar) parent[nx][ny] = 1;
        }

        // update frontier
        for (auto [nx,ny] : next) vis[nx][ny] = true;
        frontier = move(next);
        result.push_back(bestChar);
    }

    cout << result << "\n";

    
}
