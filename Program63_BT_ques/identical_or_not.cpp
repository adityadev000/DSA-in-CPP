//p63 -> q4 -> Determine if Two Trees are Identical.
#include<iostream>
#include "tree.cpp"
#include<bits/stdc++.h>

using namespace std;

bool isIdentical(treeNode *r1, treeNode *r2)
{
    //Your Code here
    //base case 
    if(r1 == NULL && r2 == NULL ){
        return true ;
    }
    if((r1 == NULL && r2 != NULL) ||(r2 == NULL && r1 != NULL)  ){
        return false ;
    }
    
    bool left = isIdentical(r1-> left , r2 -> left) ;
    bool right = isIdentical(r1-> right , r2 -> right) ;
    bool value = r1->data == r2->data;
    if(left && right && value ){
        return true ;
    }
    else{
        return false ;
    }
    
}

int main(){

    treeNode * root1 = NULL ;
    root1= buildTree(root1) ;
    treeNode * root2 = NULL ;
    root2= buildTree(root2) ;
//2 4 7 -1 -1 5 -1 -1 3 5 -1 -1 9 -1 -1
    cout << isIdentical(root1 , root2) << endl;

}