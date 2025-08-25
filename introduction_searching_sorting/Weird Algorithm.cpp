#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
void file_out(){
    #ifndef ONLINE_JUDGE

    freopen("Error.txt", "w", stderr);
#endif
}
void fun(){
    long long n;
    cin >> n;
    while (n != 1) {
        cout << n << " ";
        if (n % 2 == 0)
            n /= 2;
        else
            n = n * 3 + 1;
    }
    cout << 1 << endl;

}





int main() {
    file_out();
    fun();

    
return 0 ;
}