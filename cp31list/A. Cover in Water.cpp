#include <bits/stdc++.h>
using namespace std; 

int main() {
    int t;
    cin >> t; // t ∈ [1, 100]
    while(t--) {
        int n; 
        cin >> n; // n ∈ [1, 100]
        string s; 
        cin >> s;

        if (s.find("...") != string::npos) {
            cout << 2 << endl;
        } else {
            cout << count(s.begin(), s.end(), '.') << endl;
        }
    }
    return 0; 
}
