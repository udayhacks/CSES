#include <bits/stdc++.h>
using namespace std;

#define N 7
string path;
bool vis[N][N];
int res = 0;

// Movement: U, D, L, R
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char dir[] = {'U', 'D', 'L', 'R'};

bool inside(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

void solve(int x, int y, int step) {
    if (x == N - 1 && y == 0) {
        if (step == 48) res++;
        return;
    }
    if (step >= 48) return;

    vis[x][y] = true;

    // Dead-end pruning (U-shaped block traps)
    if ((x > 0 && x < 6 && vis[x - 1][y] && vis[x + 1][y] && !vis[x][y - 1] && !vis[x][y + 1]) ||
        (y > 0 && y < 6 && vis[x][y - 1] && vis[x][y + 1] && !vis[x - 1][y] && !vis[x + 1][y])) {
        vis[x][y] = false;
        return;
    }

    char c = path[step];
    for (int i = 0; i < 4; ++i) {
        if (c != '?' && c != dir[i]) continue;
        int nx = x + dx[i], ny = y + dy[i];
        if (!inside(nx, ny) || vis[nx][ny]) continue;
        solve(nx, ny, step + 1);
    }

    vis[x][y] = false;
}

int main() {
    cin >> path;
    solve(0, 0, 0);
    cout << res << '\n';
}
