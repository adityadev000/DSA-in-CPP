//p70 -> q2 ->   Find K-th smallest Element in BST
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
template<class T >
class BinaryTreeNode
    {
    public:
        T data;
        BinaryTreeNode<int> *left, *right;
        
        BinaryTreeNode (T x) {
            this -> data = x ;
            this -> left = NULL ;
            this -> right = NULL ;
        }
        
    };
int solve(BinaryTreeNode<int>* root,int& i, int k){
    //base case 
    if( root == NULL ) return -1 ;

    int left = solve (root -> left  , i , k );
    if(left != -1 ){
        return left ; 
    }
    i++ ;
    if( i== k){
        return root -> data ;
    }
     return  solve (root -> right  , i , k );

}
int kthSmallest(BinaryTreeNode<int>* root, int k) {
    // Write your code here.
    int i =0; 
    int ans = solve (root , i , k );
    return ans ; 
}

int main(){

    BinaryTreeNode<int> * root = new BinaryTreeNode<int> (65) ;
    BinaryTreeNode<int> * rl = new BinaryTreeNode<int> (56) ;
    BinaryTreeNode<int> * rr = new BinaryTreeNode<int> (92) ;
    BinaryTreeNode<int> * rll = new BinaryTreeNode<int> (43) ;
    BinaryTreeNode<int> * rrl = new BinaryTreeNode<int> (90) ;

    root -> left = rl ;root -> right =rr ; rl -> left  = rll ;rr -> left = rrl ;

    cout << kthSmallest(root , 2 ) << endl;


}