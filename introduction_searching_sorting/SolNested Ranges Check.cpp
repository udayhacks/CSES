#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n;

void solve(vector<vector<int>> ranges) {
    vector<int> check(n + 1);

    int pos = 0;
    for (auto r : ranges) {
        if (pos >= -r[1]) {
            check[r[2]] = 1;
        }
        pos = max(pos, -r[1]);
    }

    for (int i = 1; i <= n; i++) {
        cout << check[i] << " ";
    }
    cout << "\n";
}

int main() {
    cin >> n;

    vector<vector<int>> ranges1;
    vector<vector<int>> ranges2;

    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        ranges1.push_back({y, -x, i});
        ranges2.push_back({x, -y, i});
    }

    sort(ranges1.begin(), ranges1.end());
    sort(ranges2.begin(), ranges2.end());
    for (auto &r : ranges1) {
        cout<<r[0]<<r[1]<<r[2]<<" "; // Restore original x value for output
    }
    cout<<"\n";
    for (auto &r : ranges2) {   
        cout<<r[0]<<r[1]<<r[2]<<" "; // Restore original y value for output
    }
    cout<<"\n";

    solve(ranges1);//contained  end-value y  have to be sorted and find max y that is take other ranges into it 
    solve(ranges2);// contains start-value x sort assending and y value should be max pair is (least x, max y) 
}