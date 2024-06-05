//p70 -> q4 ->  LCA of Two Nodes In A BST
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        
        TreeNode(int x) {
            this -> data = x ;
            this -> left = NULL ;
            this -> right = NULL ;
        }
        
    };
TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{

    while(root != NULL ){
        if(root -> data < P-> data &&root -> data < Q-> data ){
            root = root -> right ;
        }
        else if(root -> data > P-> data &&root -> data > Q-> data){
           root = root -> left ;
        }
        else 
        return root ;

    }

    //  if(root == NULL ){

    // }
    // if(root -> data < P-> data &&root -> data < Q-> data ){
    //     return LCAinaBST(root -> right  , P ,Q) ;
    // }
    // if(root -> data > P-> data &&root -> data > Q-> data){
    //      return LCAinaBST(root -> left   , P ,Q) ;
    // }
    // return root ;



}
int main(){
    TreeNode* root = new TreeNode (65) ;
    TreeNode* rl = new TreeNode (56) ;
    TreeNode* rr = new TreeNode (92) ;
    TreeNode* rll = new TreeNode (43) ;
    TreeNode* rrl = new TreeNode (90) ;

    root -> left = rl ;root -> right =rr ; rl -> left  = rll ;rr -> left = rrl ;

    TreeNode* ans = LCAinaBST(root , rl , rrl) ;
    cout << ans -> data << endl;


}