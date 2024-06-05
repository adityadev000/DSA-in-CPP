//p71 -> q3 -> convert normal bst to balanced bst.
//A Balanced BST is defined as a BST, in which the height of two
//  subtrees of every node differs no more than 1.
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

template <class T>
    class TreeNode
    {
    public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

    };

void inorder (TreeNode<int>* root, vector<int>& in ){
    //base
    if(root == NULL ){
        return ;
    }
    inorder(root -> left , in );
    in.push_back(root -> data) ;
    inorder(root -> right , in );

}

TreeNode<int>* solve( int s ,int e , vector<int>& in) {
    //base case 
    if(s>e ){
        return NULL ;
    }
    int mid = s+(e-s)/2 ;
    TreeNode<int> * temp = new TreeNode<int> (in[mid] ) ;
    temp -> left = solve(  s ,mid-1 , in  ) ;
    temp -> right = solve( mid+1 ,e , in  ) ;
    return temp  ;
}
TreeNode<int>* balancedBst(TreeNode<int>* root) {
    // Write your code here.
    vector<int> in ;
    inorder(root, in ) ;

    int s =0 , e = in.size()- 1 ;
    return solve(  s ,e , in  ) ;

}


int main(){

    cout << "Alright !!!!!!!!!!!" << endl;


}