#include <bits/stdc++.h>
using namespace std;

struct Movie {
    int a, b; // start and end times
    bool operator<(const Movie &o) const {
        return b < o.b; // sort by ending time
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<Movie> movies(n);
    for (int i = 0; i < n; i++) {
        cin >> movies[i].a >> movies[i].b;
    }

    // Step 1: Sort movies by their end time
    sort(movies.begin(), movies.end());

    // Step 2: Initialize "k" club members, all free at time 0
    multiset<int> watchers;
    for (int i = 0; i < k; i++) watchers.insert(0);

    int ans = 0;

    // Step 3: Process each movie
    for (auto &m : movies) {
        // Find a watcher whose last movie ended <= current movie's start
        auto it = watchers.upper_bound(m.a);

        if (it == watchers.begin()) {
            // No watcher free before this movie starts → skip movie
            continue;
        }

        // Step 4: Assign movie to the watcher ending latest but <= m.a
        --it; // move back one step (because upper_bound gives > a)
        watchers.erase(it); // remove old end time
        watchers.insert(m.b); // insert new end time after watching this movie
        ans++; // movie successfully assigned
    }

    cout << ans << "\n";
    return 0;
}
