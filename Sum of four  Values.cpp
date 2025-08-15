#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long x;
    cin >> n >> x;

    vector<pair<long long,int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1; // store original index
    }

    sort(a.begin(), a.end()); // sort by value

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long target2 = x - a[i].first - a[j].first;
            int l = j + 1, r = n - 1;
            while (l < r) {
                long long s = a[l].first + a[r].first;
                if (s == target2) {
                    cout << a[i].second << " " << a[j].second << " "
                         << a[l].second << " " << a[r].second << "\n";
                    return 0;
                }
                else if (s < target2) l++;
                else r--;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
}
