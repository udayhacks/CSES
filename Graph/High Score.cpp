#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll NEG_INF = -4e18; // very negative

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    struct Edge { int u, v; ll w; };
    vector<Edge> edges(m);
    vector<vector<int>> adj(n+1);

    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        adj[edges[i].u].push_back(edges[i].v);
    }

    vector<ll> dist(n+1, NEG_INF);
    dist[1] = 0;

    // Bellman-Ford (n-1 times)
    for (int i = 1; i <= n-1; i++) {
        for (auto &e : edges) {
            if (dist[e.u] != NEG_INF && dist[e.u] + e.w > dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }

    // Detect positive cycle reachable from 1 and reaching n
    vector<int> affected;
    for (auto &e : edges) {
        if (dist[e.u] != NEG_INF && dist[e.u] + e.w > dist[e.v]) {
            affected.push_back(e.v);
        }
    }

    // BFS/DFS from affected nodes
    vector<int> vis(n+1, 0);
    queue<int> q;
    for (int x : affected) {
        q.push(x);
        vis[x] = 1;
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == n) {
            cout << -1 << "\n";
            return 0;
        }
        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                q.push(v);
            }
        }
    }

    cout << dist[n] << "\n";
    return 0;
}
