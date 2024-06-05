// Size of Largest BST in Binary Tree.
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

class info {
    public :
    int maxi ;
    int mini ;
    bool isBST;
    int size ;
};

info solve(TreeNode * root , int & ans ) {
    if(root == NULL )
    return {INT_MIN,INT_MAX,true , 0 };

    info left = solve(root -> left  , ans);
    info right = solve(root -> right  , ans);

    info curr ;
    curr.size = left.size + right.size +1 ;
    curr.maxi = max(root -> data , right.maxi) ;
    curr.mini = min(root -> data , left.mini) ;

    if(left.isBST && right.isBST &&(root -> data > left.maxi  && root -> data < right.mini)) {
        curr.isBST = true ;
    }
    else curr.isBST = false ;

    if(curr.isBST){
        ans = max(ans,curr.size) ;
    }
    return curr ;
}
int largestBST(TreeNode * root){
    // Write your code here.
    int maxsize= 0; 
    info temp = solve(root , maxsize ) ;
    return maxsize;

}

int main(){

    cout << "Alright!!!!!!!!" << endl;


}