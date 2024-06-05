//p65 -> q2 -> Lowest Common Ancestor in a Binary Tree
#include<iostream>
#include "tree.cpp"
#include<bits/stdc++.h>

using namespace std;

Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
       if(root == NULL ){
           return NULL ;
       }
       if(root-> data == n1 || root-> data == n2){
           return root ;
       }
       
       Node* left = lca(root-> left  ,n1 ,n2);
       Node* right = lca(root-> right ,n1 ,n2);
       
       if(left != NULL && right != NULL ){
           return root ;
       }
       else if(left != NULL && right == NULL){
           return left ;
       }
       else if(right != NULL && left == NULL){
           return right ;
       }
       else{
           return NULL ;
       }
    }

int main(){

    Node * root = NULL ;
    root= buildTree(root) ;
//2 4 7 -1 -1 5 -1 -1 3 5 -1 -1 9 -1 -1
    Node* ans = lca(root ,4,5) ;
    cout << ans-> data << endl;

}
