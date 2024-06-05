//p64 -> q2 -> Boundary Traversal of binary tree
#include<iostream>
#include "tree.cpp"
#include<bits/stdc++.h>

using namespace std;

void traverse_left(Node* root, vector<int> &ans) {
    //base case
    if( (root == NULL) || (root->left == NULL && root->right == NULL) )
        return ;
        
    ans.push_back(root->data);
    if(root->left)
        traverse_left(root->left, ans);
    else
        traverse_left(root->right, ans) ;
}

void traverse_leaf(Node* root, vector<int> &ans) {
    //base case
    if(root == NULL)
        return ;
        
    if(root->left == NULL && root->right == NULL) {
        ans.push_back(root->data);
        return;
    }
    
    traverse_leaf(root->left, ans);
    traverse_leaf(root->right, ans);
}

void traverse_right(Node* root, vector<int> &ans) {
    //base case
    if( (root == NULL) || (root->left == NULL && root->right == NULL) )
        return ;
        
    if(root->right)
        traverse_right(root->right, ans);
    else
        traverse_right(root->left, ans) ;
    ans.push_back(root->data);
} 
vector <int> boundary(Node *root)
{
    vector<int> ans;
    if(root == NULL)
        return ans;
        
    ans.push_back(root->data);
    
    //left part print/store
    traverse_left(root->left, ans);
    
    //traverse Leaf Nodes
    
    //left subtree
    traverse_leaf(root->left, ans);
    //right subtree
    traverse_leaf(root->right, ans);
    
    //traverse right part
    traverse_right(root->right, ans);
    
    return ans; 
}

int main(){

    Node * root = NULL ;
    root= buildTree(root) ;
//2 4 7 -1 -1 5 -1 -1 3 5 -1 -1 9 -1 -1
    vector<int> a = boundary(root) ;

    for(auto i : a){
        cout << i << " " ;
    }cout  << endl;


}