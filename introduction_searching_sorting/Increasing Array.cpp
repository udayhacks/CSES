#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long> a(n);
    for (auto &x : a) cin >> x;

    long long moves = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] < a[i - 1]) {
            moves += (a[i - 1] - a[i]);
            a[i] = a[i - 1]; // make it non-decreasing
        }
    }

    cout << moves << "\n";
    return 0;
}
