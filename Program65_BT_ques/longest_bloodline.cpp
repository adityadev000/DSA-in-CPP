//p65 -> q1 -> sumof longest bloodline of a tree
#include<iostream>
#include "tree.cpp"
#include<bits/stdc++.h>

using namespace std;

void solve (Node * root , int len , int &maxlen , int sum , int &maxsum ){
        if(root == NULL){
            if(len > maxlen ){
                maxlen = len ;
                maxsum =sum ;
            }
            else if(len == maxlen) {
                maxsum = max(sum , maxsum  ) ;
            }
            return ;
        }
        sum = sum + root->data;
        solve(root-> left , len+1 ,maxlen, sum ,maxsum );
        solve(root-> right , len+1 ,maxlen, sum ,maxsum );
    }

    
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        int len =0 ;
        int maxlen = 0 ;
        
        int sum = 0 ;
        int maxsum = INT_MIN ;
        
        solve(root , len ,maxlen, sum , maxsum );
        
        return maxsum ;
    }

int main(){

    Node * root = NULL ;
    root= buildTree(root) ;
//2 4 7 -1 -1 5 -1 -1 3 5 -1 -1 9 -1 -1
    cout <<  sumOfLongRootToLeafPath(root) << endl ;


}