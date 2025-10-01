#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<int> freq(n + 1, 0);
        for (int x : a) {
            if (x <= n) freq[x]++;
        }

        int length = 0;
        for (int x = 1; x <= n; x++) {
            length += (freq[x] / x) * x;
        }

        cout << length << "\n";
    }

    return 0;
}
