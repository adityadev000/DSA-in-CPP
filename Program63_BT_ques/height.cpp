//p63 -> q1 -> Height of Binary Tree.
#include<iostream>
#include "tree.cpp"
#include<bits/stdc++.h>

using namespace std;


int height(treeNode* node){
        //base case 
        if(node == NULL) return 0 ;
        
        int left = height(node -> left );
        int right = height (node -> right) ;
        
        int ans = max(left ,right) +1 ;
        
        return ans  ;
    }

int main(){

    treeNode * node = NULL ;
    node= buildTree(node) ;
//2 4 7 -1 -1 8 -1 -1 3 5 -1 -1 9 -1 -1
    cout << height(node) << endl;



}