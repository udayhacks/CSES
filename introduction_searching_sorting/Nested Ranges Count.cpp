#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct Range {
    int l, r, idx;
    bool operator<(const Range &other) const {
        if (l == other.l) return r > other.r;
        return l < other.l;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<Range> ranges(n);
    for (int i = 0; i < n; i++) {
        cin >> ranges[i].l >> ranges[i].r;
        ranges[i].idx = i;
    }

    vector<int> contains(n), contained_in(n);
    ordered_set<pair<int, int>> rounded_set;

    sort(ranges.begin(), ranges.end());

    // Pass 1: contained_in
    for (int i = 0; i < n; i++) {
        rounded_set.insert({ranges[i].r, ranges[i].idx});
        int less_count = rounded_set.order_of_key({ranges[i].r, INT_MIN});
        contained_in[ranges[i].idx] = (int)rounded_set.size() - less_count - 1;
    }

    rounded_set.clear();

    // Pass 2: contains
    for (int i = n - 1; i >= 0; i--) {
        rounded_set.insert({ranges[i].r, ranges[i].idx});
        int cnt = rounded_set.order_of_key({ranges[i].r, INT_MAX});
        contains[ranges[i].idx] = cnt - 1; // exclude itself
    }

    for (int x : contains) cout << x << " ";
    cout << "\n";
    for (int x : contained_in) cout << x << " ";
    cout << "\n";
}
