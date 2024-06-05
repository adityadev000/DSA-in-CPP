// p71 -> q1 ->Two Sum IV - Input is a BST

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

void inorder (BinaryTreeNode<int>* root, vector<int>& in ){
    //base
    if(root == NULL ){
        return ;
    }
    inorder(root -> left , in );
    in.push_back(root -> data) ;
    inorder(root -> right , in );

}
bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	//Write your code here
    vector<int> in ;
    inorder(root, in ) ;

    int i =0 , j= in.size() -1 ;
    while(i < j ){
        int sum = in[i] + in[j] ;
        if(sum == target )  return true; 
        
        else if (sum > target ) j-- ;

        else i++ ;
    }
    return false ;
}

int main(){

    cout << "Alright!!!!!!!!!" << endl;


}