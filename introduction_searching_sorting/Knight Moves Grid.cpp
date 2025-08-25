#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int dx[] = {-2, -1, -2, -1, 1, 2, 1, 2};
int dy[] = {-1, -2, 1, 2, -2, -1, 2, 1};

void knight_moves(int n) {
    vector<vector<int>> dist(n, vector<int>(n, -1));
    queue<pair<int, int>> q;
    dist[0][0] = 0;
    q.push({0, 0});

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < n && ny < n && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    // Print the result
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    fastio();
    int n;
    cin >> n;
    knight_moves(n);
    return 0;
}
