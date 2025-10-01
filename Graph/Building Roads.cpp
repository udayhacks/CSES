//// CP template ////
#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nl "\n"
#define pb push_back
#define ff first
#define ss second

typedef long long ll;

vector<vector<int>> graph;
vector<int> visited;

void dfs(int node) {
    if (visited[node]) return;
    visited[node] = 1;
    for (auto &i : graph[node]) {
        dfs(i);
    }
}

void algorithm() {
    int n, m; 
    cin >> n >> m;
    
    graph.assign(n + 1, {});
    visited.assign(n + 1, 0);

    while (m--) {
        int a, b; 
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
 
    vector<int> reps;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            reps.push_back(i); // representative of this component
        }
    }

    int k = reps.size() - 1;
    cout << k << nl;
    for (int i = 0; i < k; i++) {
        cout << reps[i] << " " << reps[i+1] << nl;
    }
}

int main() {
    fastio();
    algorithm();
    return 0;
}
