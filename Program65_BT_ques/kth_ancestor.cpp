//p65 -> q4 -> Kth Ancestor in a Tree.
#include<iostream>
#include "tree.cpp"
#include<bits/stdc++.h>

using namespace std;

Node* solve(Node *root, int &k, int node){
    if(root == NULL )return NULL;
    if(root -> data == node ){
        return root ;
    }
    
    Node* left = solve(root-> left , k , node );
    Node* right = solve(root-> right , k , node );
    
    if(left != NULL && right == NULL ){
        k-- ;
        if(k <=0 ){
            //lock 
            k = INT_MAX;
            return root ;
        }
        return left ;
    }
    if(right != NULL && left == NULL ){
        k-- ;
        if(k <=0 ){
            //lock 
            k = INT_MAX;
            return root ;
        }
        return right ;
    }

        return NULL ;
}
int kthAncestor(Node *root, int k, int node)
{
    // Code here
    Node* ans = solve(root , k , node );
    
    if(ans == NULL || ans -> data == node ) return -1;
    
    return ans -> data ;
}

int main(){

    Node * root = NULL ;
    root= buildTree(root) ;
//2 4 7 -1 -1 5 -1 -1 3 5 -1 -1 9 -1 -1
    cout <<  kthAncestor(root ,2, 7) << endl ;


}