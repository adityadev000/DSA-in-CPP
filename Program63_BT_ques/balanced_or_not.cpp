//p63 -> q3 -> Check for Balanced Tree.
/*Given a binary tree, find if it is height balanced or not. 
A tree is height balanced if difference between heights of left and right
 subtrees is not more than one for all nodes of tree. */

 #include<iostream>
 #include "tree.cpp"
 #include<bits/stdc++.h>
 
 using namespace std;
 
 pair<bool,int> fastbalanced (treeNode * root ){
        if( root == NULL) {
            pair<bool,int> p  = make_pair (true , 0) ;
            return p ;
        }
        pair<bool,int> left = fastbalanced(root -> left) ;
        pair<bool,int> right = fastbalanced(root -> right) ;
        
        bool diff = abs(left.second - right.second) <=1 ;
        
        pair<bool, int  > ans  ;
        ans.second = max(left.second, right.second) + 1;
        if(left.first && right.first && diff){
            ans.first = true ;
        }
        else{
            ans.first = false ;
        }
        return ans  ;
    }
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(treeNode *root)
    {
        return fastbalanced(root).first ;
    }
 
 int main(){
 
    treeNode * root = NULL ;
    root= buildTree(root) ;
//2 4 7 -1 -1 5 -1 -1 3 5 -1 -1 9 -1 -1
    cout << isBalanced(root) << endl;
 
 
 }