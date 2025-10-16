#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k, x, a, b, c;
    cin >> n >> k >> x >> a >> b >> c;

    long long ans = 0;
    long long curr = x;
    vector<int> last(32, -1); // last index each bit was set

    for (int i = 0; i < n; i++) {
        if (i > 0) curr = (1LL * a * curr + b) % c;

        // Update last indices for bits set in current number
        for (int bit = 0; bit < 32; bit++) {
            if (curr & (1 << bit)) last[bit] = i;
        }

        if (i >= k - 1) {
            long long window_or = 0;
            for (int bit = 0; bit < 32; bit++) {
                if (last[bit] >= i - k + 1)
                    window_or |= (1LL << bit);
            }
            ans ^= window_or;
        }
    }

    cout << ans << "\n";
}
