
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
template<class T> 
class BinaryTreeNode {
       public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };



BinaryTreeNode<int>* solve(vector<int> &preorder , int min ,int max ,int & i ) {
    //base case 
    if(preorder[i] < min || preorder[i] > max || i>= preorder.size()  ){
        return NULL ;
    }
    BinaryTreeNode<int>* temp = new BinaryTreeNode<int> (preorder[i++]) ;

    temp -> left = solve(preorder , min , temp -> data , i  ) ;
    temp -> right = solve(preorder  , temp -> data, max, i ) ;

    return temp ;
}
BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    // Write your code here.
    int i =0 ; 
    return solve(preorder , INT_MIN , INT_MAX , i);
}

int main(){

    cout << "Alright!!!!!" << endl;


}