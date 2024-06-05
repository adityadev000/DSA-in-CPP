//p64 -> q6,7 -> left and right view
#include<iostream>
#include "tree.cpp"
#include<bits/stdc++.h>

using namespace std;

void solveleft(Node* root , vector<int> & ans , int level ){
    if(root == NULL) return  ;
    
    if(level == ans.size() ){
        ans.push_back(root-> data) ;
    }
    
    solveleft(root->left , ans , level+1) ;
    solveleft(root->right , ans , level+1) ;
}

vector<int> leftView(Node *root)
{
   // Your code here
   int level = 0 ;
   vector<int> ans ;
    solveleft (root ,ans ,level) ;
   
   return ans ; 
}

void solveright(Node* root , vector<int> & ans , int level ){
    if(root == NULL) return  ;
    
    if(level == ans.size() ){
        ans.push_back(root-> data) ;
    }
    
    solveright(root->right , ans , level+1) ;
    solveright(root->left , ans , level+1) ;
}

vector<int> rightView(Node *root)
{
   // Your code here
   int level = 0 ;
   vector<int> ans ;
    solveright (root ,ans ,level) ;
   
   return ans ; 
}

int main(){

    Node * root = NULL ;
    root= buildTree(root) ;
//2 4 7 -1 -1 5 -1 -1 3 5 -1 -1 9 -1 -1
    vector<int> a = leftView (root ) ;
    vector<int> b = rightView (root) ;

    for(auto i : a){
        cout << i << " " ;
    }cout  << endl;

    for(auto i : b){
        cout << i << " " ;
    }cout  << endl;


}