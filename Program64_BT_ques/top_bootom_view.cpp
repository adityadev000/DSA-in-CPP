//p64 -> q4,5 -> top and bottom view
#include<iostream>
#include "tree.cpp"
#include<bits/stdc++.h>

using namespace std;

vector<int> top_bootom_View(Node *root , char c) {
    //Your code here
    map<int, int> m ;
    queue <pair<Node* , int> >q ; //node , hd
    vector<int> ans  ; 
    
    if(root == NULL) return ans  ;
    q.push(make_pair(root , 0)) ;
    
    while(!q.empty() ){
        pair<Node* , int> front = q.front() ;
        q.pop() ;
        
        Node* f= front.first ;
        int hd = front.second ;
        
        if(c == 't'){
        if(m.find(hd) == m.end())
        m[hd] = f -> data ;
        }

        else{
        m[hd] = f -> data ;
        }
        if(f -> left)
            q.push(make_pair(f->left, hd-1 )) ;
        
        
        if(f -> right)
            q.push(make_pair(f->right, hd+1 ) );
        
        
    }
    
    for(auto  i : m ){
        ans.push_back(i.second);
    }
    return ans  ;
    
}



int main(){

    Node * root = NULL ;
    root= buildTree(root) ;
//2 4 7 -1 -1 5 -1 -1 3 5 -1 -1 9 -1 -1
    vector<int> a = top_bootom_View (root , 't') ;
    vector<int> b = top_bootom_View (root , 'b') ;

    for(auto i : a){
        cout << i << " " ;
    }cout  << endl;

    for(auto i : b){
        cout << i << " " ;
    }cout  << endl;


}