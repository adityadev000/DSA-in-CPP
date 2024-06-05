//p64 -> q3 -> Boundary Traversal of binary tree  Vertical Traversal of Binary Tree
#include<iostream>
#include "tree.cpp"
#include<bits/stdc++.h>

using namespace std;

vector<int> verticalOrder(Node *root)
{
    //Your code here no need of level 
    map<int ,vector<int> >  node;
    queue< pair<Node*, int > > q;
    vector<int> ans;
    
    if( root == NULL ) return ans  ;
     q.push(make_pair(root,0));
    
    while(!q.empty()){
       pair<Node* , int> f  = q.front() ;
       q.pop() ;
       
       Node* front = f.first ;
       int hd = f.second ;
       
       node [hd].push_back(front -> data) ;
       
       if(front -> left ){
           q.push(make_pair(front-> left , hd-1)) ;
       }
       if(front -> right ){
           q.push(make_pair(front-> right , hd+1)) ;
       }
    }
    
    for(auto i: node) {
        
        for(auto j:i.second) {
                ans.push_back(j);
        }
    }
    return ans;
}

int main(){

    Node * root = NULL ;
    root= buildTree(root) ;
//2 4 7 -1 -1 5 -1 -1 3 5 -1 -1 9 -1 -1
    vector<int> a = verticalOrder(root) ;

    for(auto i : a){
        cout << i << " " ;
    }cout  << endl;


}