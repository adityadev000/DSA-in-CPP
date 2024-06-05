#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Node {
public :
    int data ;
    Node* left ;
    Node* right ;
    Node(int d){
        this -> data = d ;
        left = NULL ;
        right =NULL ;
    }
};

Node*  buildTree(Node* root){
    cout << "Enter data " << endl;
    int n ;
    cin >> n ;
    root = new Node(n) ;

    if(n == -1 ){
        return NULL ;
    }

    cout << "Enter data for inserting in left of " << n << endl;
    root-> left = buildTree(root -> left ); 

    cout << "Enter data for inserting in right of " << n << endl;
    root-> right = buildTree(root -> right ); 

    return root ;
}

void levelOrderTraversal(Node* root) {
    queue<Node*> q ;
    q.push(root) ;
    q.push(NULL) ;

    while(!q.empty()) {
        Node * temp  = q.front() ;
        q.pop() ;

        if( temp == NULL ){
            cout  << endl;

            if(!q.empty()) {
                q.push(NULL) ;
            }
        }
        else {
            cout << temp -> data << " ";
            if(temp -> left )
            q.push (temp -> left );

            if(temp -> right)
            q.push (temp -> right );
        }
    }
}

void InOrder(Node* root){
    // base case 
    if(root == NULL ) return ;

    InOrder(root -> left );
    cout << root -> data << " ";
    InOrder(root -> right );
}

void PreOrder(Node* root){
    // base case 
    if(root == NULL ) return ;

    cout << root -> data << " ";
    PreOrder(root -> left );
    PreOrder(root -> right );
}

void PostOrder(Node* root){
    // base case 
    if(root == NULL ) return ;

    PostOrder(root -> left );
    PostOrder(root -> right );
    cout << root -> data << " ";
}

