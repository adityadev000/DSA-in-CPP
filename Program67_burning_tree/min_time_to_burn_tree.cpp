// p68 -> Find the minimum time required to burn the complete binary tree if the target is set on fire.
#include<iostream>
#include "tree.cpp" 
#include<bits/stdc++.h>

using namespace std;
Node* createmapping (Node* root, int target ,map<Node*, Node* > &  NtoP  ){
        Node*  res = NULL ;
        queue<Node * > q ;
        q.push(root) ;
        
        while(!q.empty()) {
            Node * f = q.front() ;
            q.pop() ;
            
            if( f-> data == target ) res = f ;
            
            if(f -> left ){
                NtoP[f-> left] = f ;
                q.push(f-> left);
            }
            if(f -> right ){
                NtoP[f-> right] = f ;
                q.push(f-> right);
            }
        }
        return res ;
    }
    int burntree (Node* targetNode ,map<Node*, Node* > NtoP  ){
        map<Node*, bool > visited ;
        queue<Node*> q ;
        q.push(targetNode) ;
        visited[targetNode] = 1 ;
        int ans= 0 ; // time 
        
        while(!q.empty() ){
            bool flag = 0; //indicated new node is added or not. 
            int size = q.size() ;
            for(int i = 0;i < size ;i ++ ){
                Node * front = q.front () ;
                q.pop() ;
                if(front -> left && visited[front -> left] == 0 ){
                    q.push(front -> left ) ;
                    visited[front -> left] =  1;
                    flag = 1 ;
                }
                if(front -> right && visited[front -> right] == 0 ){
                    q.push(front -> right ) ;
                    visited[front -> right] =  1;
                    flag = 1 ;
                }
                if(NtoP[front]  && visited[NtoP[front]] == 0 ) {
                    q.push(NtoP[front]  ) ;
                    visited[NtoP[front] ] =  1;
                    flag = 1 ;
                }
            }
            if(flag) ans ++ ;
        }
        return ans ; 
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        map<Node*, Node* > NtoP ;
        createmapping(root ,target , NtoP) ;
        
        Node* targetNode = createmapping(root ,target , NtoP) ;
        int ans = burntree(targetNode , NtoP) ;
        return ans ;
    }


int main(){

    Node * root = NULL ;
    root= buildTree(root) ;
//1 2  4 -1 -1 5 7 -1 -1 8 -1 -1 3 -1 6 -1 9 -1 10 -1 -1

    cout << minTime(root , 8) << endl;


}