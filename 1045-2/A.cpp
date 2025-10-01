#include <bits/stdc++.h>
using namespace std;

// Function to check if a half is possible
bool possible(int x, int y) {
    return max(x, y) <= 2 * (min(x, y) + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int first_half_R = a;
        int first_half_K = b;
        int second_half_R = c - a;
        int second_half_K = d - b;

        if (possible(first_half_R, first_half_K) && possible(second_half_R, second_half_K)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
