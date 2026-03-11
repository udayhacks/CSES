#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define nl '\n'
#define debug(x) cerr << #x <<" == "; cerr<<x; cerr << endl;

void file_out(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
#endif
}
long long ceil_division(long long a, long long b) {
    return (a + b - 1) / b;
}

// tree ;
// insert ;
// height ;
// // balanced ;
// diameter ;




struct node {
    int data ;
    node * left;
    node *right;

    node(int val ){
        data = val;
        left = right = nullptr;
    }
};


node* insert(node *root,int val){
    
    if ( root == nullptr){
         return new node(val);
    }
    if ( val < root->data){
        root->left = insert(root->left,val);
    }else{
        
         root->right = insert(root->right,val);
    }
    return root;

}


void print(node *root){
    if ( root ==nullptr){
        return;
    }
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}


int height(node*root){
    if( root ==nullptr){
        return 0;
    }
    return 1+max(height(root->left),height(root->right));
}

int checkBalance(node*root){
    if (root ==nullptr) return 0;

    int left = checkBalance(root->left);
    if ( left ==-1) return -1;
    int right = checkBalance(root->right);
    if ( right == -1) return -1;
    if(abs(right-left)>1) return -1;

    return 1+max(left,right);


}


// diameter

int diameter(node *root , int& d){
  
  if ( root == nullptr) return 0;
  
  int left = diameter(root->left,d);
  int right = diameter(root->right,d);

  d = max(left+right+1,d);
  return 1+max(left,right);
}


// balanced

bool is_balanced(node *root){
  return (checkBalance(root) != -1);
}





void algorithm() {





  int n ; 
  cin >> n ;
  // here input number of nodes ;
  
  node *root = nullptr;
  
  for ( int i = 0;i<n;i++){
    // take space-separated node as integers;
        int a ;cin >>a;
       root = insert(root,a); 
    }

    print(root);
    cout<<'\n';
    cout<<"height is "<<height(root)<<endl;
    (is_balanced(root)) ? cout<<"Is balanced"<<'\n' : cout<<"Not balanced" <<'\n';
    int d= 0;
    int val = diameter(root,d);
    cout<<d<<'\n'; 








    

}

int main(){
    file_out();
    int test =1;
    cin >> test;
    while (test--) algorithm();
    return 0;
}
