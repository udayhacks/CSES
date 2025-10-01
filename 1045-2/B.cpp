#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        // Check if there are k consecutive '1's
        int cnt = 0;
        bool impossible = false;
        for (char c : s) {
            if (c == '1') {
                cnt++;
                if (cnt >= k) {
                    impossible = true;
                    break;
                }
            } else {
                cnt = 0;
            }
        }

        if (impossible) {
            cout << "NO\n";
            continue;
        }

        // Otherwise, construct permutation
        vector<int> perm(n);
        vector<int> ones, zeros;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') ones.push_back(i);
            else zeros.push_back(i);
        }

        int num = 1;
        for (int idx : ones) perm[idx] = num++;
        for (int idx : zeros) perm[idx] = num++;

        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            cout << perm[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
