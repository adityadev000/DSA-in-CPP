//p62 -> count no. of leaf nodes in a binary tree. 
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
template <typename T>
class BinaryTreeNode {
public :
    T data ;
    BinaryTreeNode<T>* left ;
    BinaryTreeNode<T>* right ;
    BinaryTreeNode(T d){
        this -> data = d ;
        left = NULL ;
        right =NULL ;
    }
};

void inorder(BinaryTreeNode<int> * root, int &count) {
    //base case
    if(root == NULL) {
        return ;
    }

    inorder(root->left, count);
   	
    //leaf node
    if(root->left == NULL && root->right == NULL) {
        count++;
    }
    
    inorder(root->right, count);

}


int noOfLeafNodes(BinaryTreeNode<int> *root){
    int cnt = 0;
    inorder(root, cnt);
    return cnt;
}
int main(){

    BinaryTreeNode<int> * root = new BinaryTreeNode<int> (1);
    BinaryTreeNode<int> * l1 = new BinaryTreeNode<int> (3);
    BinaryTreeNode<int> * l2 = new BinaryTreeNode<int> (7);
    BinaryTreeNode<int> * r2 = new BinaryTreeNode<int> (11);
    BinaryTreeNode<int> * r1 = new BinaryTreeNode<int> (5);
 
    root -> left = l1 ;root -> right  = r1; l1 -> left = l2 ;l1 -> right  = r2 ;


    cout << noOfLeafNodes(root) << endl;
 }