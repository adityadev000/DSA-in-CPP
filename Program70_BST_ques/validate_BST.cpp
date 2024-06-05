//p70 -> q1 -> check given tree is bst or not.
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

bool solve (BinaryTreeNode<int> *root , int max , int min ){
    if( root == NULL )return true ;
    if((root -> data >= min) &&( root -> data <= max)){
        bool left =  solve(root-> left , root -> data,min);
        bool right =  solve(root-> right , max, root -> data);
        return left && right ;
    }
   else{
    return false ;
   }
}
bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    return  solve(root , INT_MAX,INT_MIN);

}

int main(){

    BinaryTreeNode<int> * root = new BinaryTreeNode<int> (65) ;
    BinaryTreeNode<int> * rl = new BinaryTreeNode<int> (56) ;
    BinaryTreeNode<int> * rr = new BinaryTreeNode<int> (92) ;
    BinaryTreeNode<int> * rll = new BinaryTreeNode<int> (43) ;
    BinaryTreeNode<int> * rrl = new BinaryTreeNode<int> (90) ;

    root -> left = rl ;root -> right =rr ; rl -> left  = rll ;rr -> left = rrl ;

    cout << validateBST(root) << endl;


}