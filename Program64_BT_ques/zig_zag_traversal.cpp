//p64 -> q1 -> ZigZag Tree Traversal.
#include<iostream>
#include "tree.cpp"
#include<bits/stdc++.h>

using namespace std;

vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int> result ;
    	if(root == NULL ){
    	    return result ;
    	}
    	
    	
    	queue<Node*> q ;
    	 q.push(root) ;
    	 
    	 bool LtoR = true ;
    	 
    	 while(!q.empty()) {
    	     int size = q.size() ;
    	     vector<int> ans (size) ;
			 
    	     for(int i = 0 ; i< size ; i++) {
    	         Node* front = q.front() ;
    	         q.pop() ;
    	         
    	         int index = LtoR ? i : size - i -1 ;
    	         ans[index] = front -> data;
    	         
    	         if(front -> left ){
    	             q.push(front -> left) ;
    	         }
    	         
    	         if(front -> right ){
    	             q.push(front -> right) ;
    	         }
    	         
    	     }
    	        LtoR = ! LtoR ;
    	        for(auto i: ans) {
    	        result.push_back(i);
    	        }
    	 }
    	 return result ;
    }

int main(){

    Node * root = NULL ;
    root= buildTree(root) ;
//2 4 7 -1 -1 5 -1 -1 3 5 -1 -1 9 -1 -1
    vector<int> a = zigZagTraversal(root) ;

    for(auto i : a){
        cout << i << " " ;
    }cout  << endl;


}