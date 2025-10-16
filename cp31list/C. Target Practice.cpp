#include <bits/stdc++.h>
using namespace std;

const int score[10][10] = {

    {1,1,1,1,1,1,1,1,1,1},

    {1,2,2,2,2,2,2,2,2,1},

    {1,2,3,3,3,3,3,3,2,1},

    {1,2,3,4,4,4,4,3,2,1},

    {1,2,3,4,5,5,4,3,2,1},

    {1,2,3,4,5,5,4,3,2,1},

    {1,2,3,4,4,4,4,3,2,1},

    {1,2,3,3,3,3,3,3,2,1},

    {1,2,2,2,2,2,2,2,2,1},

    {1,1,1,1,1,1,1,1,1,1}

};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){

        vector<string> a(10);
        for (int i = 0 ;i<10;i++) cin >>a[i];
        
        int total = 0 ;
        for ( int i = 1;i<=10;i++){
            for ( int j = 0 ;j<10;j++){
                if ( a[i-1][j] == 'X'){
                    total +=(score[i-1][j]);
                    }  
                
            }
            
            
        }cout<<total<<endl;



    }


    
}
