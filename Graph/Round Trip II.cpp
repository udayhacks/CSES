#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/// doc 
/*

follow the dfs and find for visited node if is in the curent path (visiting state)
if found then we have a cycle
then reconstruct the cycle using parent array
*/

const int N = 1e5 + 5;
vector<int> adj[N];
vector<int> parent(N, -1), visited(N, 0);
int start_node = -1, end_node = -1;
int n, m;

bool dfs(int u) {
    visited[u] = 1; // visiting
    for (int v : adj[u]) {
        if (visited[v] == 0) {
            parent[v] = u;
            if (dfs(v)) return true;
        } 
        else if (visited[v] == 1) { 
            // found a back edge => cycle
            start_node = v;
            end_node = u;
            return true;
        }
    }
    visited[u] = 2; // finished
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(i)) break;
        }
    }

    if (start_node == -1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    // reconstruct cycle
    vector<int> cycle;
    cycle.push_back(start_node);
    for (int v = end_node; v != start_node; v = parent[v])
        cycle.push_back(v);
    cycle.push_back(start_node);
    reverse(cycle.begin(), cycle.end());

    cout << cycle.size() << "\n";
    for (int x : cycle) cout << x << " ";
    cout << "\n";
    return 0;
}
