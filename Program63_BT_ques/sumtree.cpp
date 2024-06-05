//p63 -> q5 -> sum Tree.
#include<iostream>
#include "tree.cpp"
#include<bits/stdc++.h>

using namespace std;

pair<bool ,int > fastisSumTree(treeNode * root) {
        if(root == NULL ){
            pair<bool ,int >p = make_pair(true ,0 );
            return p ;
        }
        if(root -> left == NULL && root -> right == NULL  ){
            pair<bool ,int >p = make_pair(true ,root-> data );
            return p ;
        }
        
        pair<bool ,int > left = fastisSumTree(root -> left );
        pair<bool ,int > right = fastisSumTree(root -> right );
        bool condn = root -> data == left.second +right.second ;
        
         pair<bool ,int >ans ; 
         if(left.first && right.first && condn){
             ans.first = true ;
             ans.second = root -> data + left.second +right.second ;
         }
         else{
             ans.first = false ;
         }
         
        return ans  ;
    }
    bool isSumTree(treeNode* root)
    {
         // Your code here
         return fastisSumTree(root).first ;
    }
int main(){

    treeNode * root1 = NULL ;
    root1= buildTree(root1) ;
//2 4 7 -1 -1 5 -1 -1 3 5 -1 -1 9 -1 -1
    cout << isSumTree(root1 ) << endl;

}