#include<iostream>
#include "tree.cpp"
#include<bits/stdc++.h>

using namespace std;

void flatten(Node *root)
    {
        //code here
        Node* curr = root ;
        while(curr != NULL ){
            if(curr -> left ){
                Node * prev = curr -> left ;
                while(prev -> right ){
                    prev = prev -> right ;
                }
                prev -> right = curr -> right ;
                curr -> right = curr -> left ;
                curr -> left = NULL ;
            }
            curr = curr -> right ;
        }
    }

int main(){

    
    Node * root = NULL ;
    root= buildTree(root) ;
//1 2 3 -1 -1 4 -1 -1 5 -1 6 -1 -1
    InOrder(root);
    cout  << endl;
    flatten(root) ;
    InOrder(root);


}