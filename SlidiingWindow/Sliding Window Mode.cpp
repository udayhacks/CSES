#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    map<int,int> freq;
    map<int,set<int>> count_map;
    vector<int> ans;
    int max_freq = 0;

    for(int i = 0; i < n; i++) {
        int x = arr[i];

        // Remove old freq
        if(freq[x] > 0) {
            count_map[freq[x]].erase(x);
            if(count_map[freq[x]].empty()) count_map.erase(freq[x]);
        }

        freq[x]++;
        count_map[freq[x]].insert(x);

        max_freq = max(max_freq, freq[x]);

        // Remove element out of window
        if(i >= k) {
            int old = arr[i-k];
            count_map[freq[old]].erase(old);
            if(count_map[freq[old]].empty()) count_map.erase(freq[old]);
            freq[old]--;
            if(freq[old] > 0) count_map[freq[old]].insert(old);
            // update max_freq if needed
            while(count_map.find(max_freq) == count_map.end() && max_freq > 0)
                max_freq--;
        }

        if(i >= k-1) {
            ans.push_back(*count_map[max_freq].begin()); // smallest element with max freq
        }
    }

    for(int x : ans) cout << x << " ";
    cout << "\n";
}
