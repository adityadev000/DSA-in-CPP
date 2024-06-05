////p63 -> q2 -> Diameter of a Binary Tree.
#include<iostream>
#include "tree.cpp"
#include<bits/stdc++.h>

using namespace std;

pair<int, int> fastdiameter (treeNode* root) {
        //base case 
        if(root == NULL ){
            pair<int,int> p = make_pair(0,0) ;
            return p ;
        }
        pair<int,int> left = fastdiameter(root -> left);
        pair<int,int> right = fastdiameter(root -> right);
        
        int op1 = left.first ;
        int op2 = right.first ;
        int op3 = left.second + right.second +1 ;
        
        pair<int, int> ans ;
        ans.first = max(op1 , max(op2,op3)) ;
        ans.second = max(left.second , right.second)  +1 ;
        
        return ans ; 
        
        
    }
    // Function to return the diameter of a Binary Tree.
    int diameter(treeNode* root) {
         return fastdiameter(root).first;
    }

int main(){

    treeNode * root = NULL ;
    root= buildTree(root) ;
//2 4 7 -1 -1 5 -1 -1 3 5 -1 -1 9 -1 -1
    cout << diameter(root) << endl;

}