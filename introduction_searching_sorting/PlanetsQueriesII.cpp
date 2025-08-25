#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define INF INT_MAX
#define pb push_back
#define ff first
#define ss second

typedef long long ll;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" == "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
template <class T> void _print(vector<T> v) {cerr << "[ "; for (T i : v) cerr << i << " "; cerr << "]\n";}

void file_out() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif
}

// ----------------------------------- BFS -------------------------------------
vector<int> bfs(vector<vector<int>> &adj, int n, int src) {
    vector<int> dist(n, INF);
    queue<int> q;
    dist[src] = 0;
    q.push(src);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int neighbor : adj[node]) {
            if (dist[neighbor] > dist[node] + 1) {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }

    return dist;
}

// ----------------------------- Process Query -------------------------------
void process_query(int a, int b, vector<vector<int>> &adj, int n) {
    vector<int> dist = bfs(adj, n, a - 1);
    if (dist[b - 1] == INF) {
        cout << -1 << endl;
    } else {
        cout << dist[b - 1] << endl;
    }
}

// ------------------------------- Main --------------------------------------
int main() {
    fastio();
    file_out();

    int n, q;
    cin >> n >> q;
    vector<vector<int>> adj(n);

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        adj[i].pb(t - 1);  // Convert to 0-based
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        process_query(a, b, adj, n);
    }

    return 0;
}
