//p65 -> q5 -> Maximum sum of Non-adjacent nodes.
#include<iostream>
#include "tree.cpp"
#include<bits/stdc++.h>

using namespace std;

pair<int,int> solve(Node* root ){
        // base case 
        if( root ==NULL ) return make_pair(0,0) ;
        pair<int,int> left = solve(root-> left );
        pair<int,int> right = solve(root-> right );
        
        pair<int, int> result ;
        result.first = root-> data + left.second + right.second ;
        result.second = max(left.first , left.second) +max(right.first , right.second) ;
        
        return result ;
        
    }
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        // Add your code here
        pair<int, int> ans = solve(root) ;
        return max(ans.first, ans.second) ;
        
    }

int main(){

    Node * root = NULL ;
    root= buildTree(root) ;
//2 4 7 -1 -1 5 -1 -1 3 5 -1 -1 9 -1 -1
    cout << getMaxSum(root) << endl;

}
