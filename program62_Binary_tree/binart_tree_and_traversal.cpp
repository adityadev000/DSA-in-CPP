//p62 -> binary tree nad its traversal.

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class node {
public :
    int data ;
    node* left ;
    node* right ;
    node(int d){
        this -> data = d ;
        left = NULL ;
        right =NULL ;
    }
};

node*  buildTree(node* root){
    cout << "Enter data " << endl;
    int n ;
    cin >> n ;
    root = new node(n) ;

    if(n == -1 ){
        return NULL ;
    }

    cout << "Enter data for inserting in left of " << n << endl;
    root-> left = buildTree(root -> left ); 

    cout << "Enter data for inserting in right of " << n << endl;
    root-> right = buildTree(root -> right ); 

    return root ;
}

void levelOrderTraversal(node* root) {
    queue<node*> q ;
    q.push(root) ;
    q.push(NULL) ;

    while(!q.empty()) {
        node * temp  = q.front() ;
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

void InOrder(node* root){
    // base case 
    if(root == NULL ) return ;

    InOrder(root -> left );
    cout << root -> data << " ";
    InOrder(root -> right );
}

void PreOrder(node* root){
    // base case 
    if(root == NULL ) return ;

    cout << root -> data << " ";
    PreOrder(root -> left );
    PreOrder(root -> right );
}

void PostOrder(node* root){
    // base case 
    if(root == NULL ) return ;

    PostOrder(root -> left );
    PostOrder(root -> right );
    cout << root -> data << " ";
}


void buildFromLevelOrder(node* &root) {
    queue<node*> q;

    cout << "Enter data for root" << endl;
    int data ;
    cin >> data;
    root = new node(data);
    
    q.push(root);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        cout << "Enter left node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1) {
            temp -> left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1) {
            temp -> right = new node(rightData);
            q.push(temp->right);
        }
    }
 }


int main(){

    node * root =NULL ;
//     root = buildTree(root) ;
// //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
//     cout << "Printing the level order traversal output " << endl;
//     levelOrderTraversal(root) ;

//     cout << "inorder traversal is:  ";
//     InOrder(root); 

//     cout << endl << "preorder traversal is:  ";
//     PreOrder(root); 

//     cout << endl << "postorder traversal is:  ";
//     PostOrder(root); 

//1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    buildFromLevelOrder(root);
    levelOrderTraversal(root);

}