#include<iostream> 
#include<set>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;


int main(){


    set<int> s1;
    s1.insert(10);
    s1.insert(20);
    cout << *s1.find(10)<<endl;
    
    return 0;
}