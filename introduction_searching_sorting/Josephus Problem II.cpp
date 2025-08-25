#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template<class T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long k;
    cin >> n >> k;

    ordered_set<int> s;
    for (int i = 1; i <= n; i++) s.insert(i);

    long long idx = 0; // current index in the circle
    while (!s.empty()) {
        idx = (idx + k) % s.size(); // next index to remove
        auto it = s.find_by_order(idx); // get element at that position
        cout << *it << " ";
        s.erase(it); // remove it
    }
    return 0;
}
