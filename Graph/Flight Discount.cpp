//// CP template ////
#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define INF 1e18
typedef long long ll;

////////////////////////////////////////////////////////////////////////////////
//                              MAIN CODE                                     //
////////////////////////////////////////////////////////////////////////////////

vector<vector<pair<int,int>>> adj, rev;

vector<ll> Dijkstra_algorithm(int src , vector<vector<pair<int,int>>> &graph){
    int n = graph.size();
    vector<ll> dis(n, INF);
    dis[src] = 0;

    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    pq.push({0, src});

    while(!pq.empty()){
        auto [d,u] = pq.top(); pq.pop();
        if(d != dis[u]) continue;
        for(auto [v,w] : graph[u]){
            if(dis[v] > d + w){
                dis[v] = d + w;
                pq.push({dis[v], v});
            }
        }
    }
    return dis;
}

void algorithm(){
    int n ,m; 
    cin >> n >> m;
    adj.assign(n+1, {});
    rev.assign(n+1, {});
    vector<array<int,3>> edge;

    for(int i = 0; i < m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        rev[b].push_back({a,c});
        edge.push_back({a,b,c});
    }

    vector<ll> stod = Dijkstra_algorithm(1, adj); // 1 → *
    vector<ll> dtos = Dijkstra_algorithm(n, rev); // * → n

    ll ans = stod[n]; // path without coupon

    for(auto &e : edge){
        int u = e[0], v = e[1], c = e[2];
        if(stod[u] == INF || dtos[v] == INF) continue;
        ans = min(ans, stod[u] + (c/2) + dtos[v]);
    }
    cout << ans << "\n";
}

int main() {
    fastio();
    algorithm();
    return 0;
}
