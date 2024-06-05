//p65 -> q3 -> k sum path.
#include<iostream>
#include "tree.cpp"
#include<bits/stdc++.h>

using namespace std;

void solve(Node* root , int k , vector<int> & ans , int &count ){
        // base case 
        if(root == NULL ) return ;
        
        ans.push_back(root-> data) ;
        
        solve(root-> left , k ,ans, count ) ;
        solve(root-> right , k ,ans, count);
        
        int n = ans.size() ;
        int sum =0 ;
        for(int i =n-1 ;i>=0 ;i -- ){
            sum+= ans[i] ;
            if(sum == k ){
                count++ ;
            }
        }
        ans.pop_back() ;
    }

    int sumK(Node *root,int k)
    {
        // code here 
        vector<int>ans ; 
        int count =0 ;
        solve(root, k, ans , count );
        return count ;
    }

int main(){

    Node * root = NULL ;
    root= buildTree(root) ;
//2 4 7 -1 -1 5 -1 -1 3 5 -1 -1 9 -1 -1
    cout <<  sumK(root, 6) << endl ;


}