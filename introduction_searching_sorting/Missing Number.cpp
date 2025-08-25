#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
void file_out(){
    #ifndef ONLINE_JUDGE

    freopen("Error.txt", "w", stderr);
#endif
}
void fun(){
    int n;
    cin >> n;

    int xor_all = 0, xor_input = 0, x;

    for (int i = 1; i <= n; ++i)
        xor_all ^= i;

    for (int i = 0; i < n - 1; ++i) {
        cin >> x;
        xor_input ^= x;
    }

    cout << (xor_all ^ xor_input) << '\n';
}





int main() {
    file_out();
    fun();

    
return 0 ;
}