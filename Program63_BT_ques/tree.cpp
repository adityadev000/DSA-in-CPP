#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class treeNode {
public :
    int data ;
    treeNode* left ;
    treeNode* right ;
    treeNode(int d){
        this -> data = d ;
        left = NULL ;
        right =NULL ;
    }
};

treeNode*  buildTree(treeNode* root){
    cout << "Enter data " << endl;
    int n ;
    cin >> n ;
    root = new treeNode(n) ;

    if(n == -1 ){
        return NULL ;
    }

    cout << "Enter data for inserting in left of " << n << endl;
    root-> left = buildTree(root -> left ); 

    cout << "Enter data for inserting in right of " << n << endl;
    root-> right = buildTree(root -> right ); 

    return root ;
}

void levelOrderTraversal(treeNode* root) {
    queue<treeNode*> q ;
    q.push(root) ;
    q.push(NULL) ;

    while(!q.empty()) {
        treeNode * temp  = q.front() ;
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

void InOrder(treeNode* root){
    // base case 
    if(root == NULL ) return ;

    InOrder(root -> left );
    cout << root -> data << " ";
    InOrder(root -> right );
}

void PreOrder(treeNode* root){
    // base case 
    if(root == NULL ) return ;

    cout << root -> data << " ";
    PreOrder(root -> left );
    PreOrder(root -> right );
}

void PostOrder(treeNode* root){
    // base case 
    if(root == NULL ) return ;

    PostOrder(root -> left );
    PostOrder(root -> right );
    cout << root -> data << " ";
}

