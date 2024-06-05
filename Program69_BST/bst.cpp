#include<iostream>
#include<bits/stdc++.h>
#include "tree.cpp"

using namespace std;

Node * insertBST(Node * root , int d) {
    if ( root == NULL ){
        root = new Node(d) ;
        return root ;
    } 

    if(d > root -> data ){
        root -> right = insertBST(root -> right , d );
    }
    else{
        root -> left  = insertBST(root -> left  , d );
    }
    return root ;
}
void createtree(Node *& root ){
    cout << "enter data " << endl;
    int d ;
    cin >> d ;

    while(d != -1 ){
        root = insertBST(root , d );
        cout << "enter data " << endl;
        cin >> d ;
    }
}

Node* find_min(Node* root ){
    Node *temp = root ;
    while(temp -> left ){
        temp = temp -> left ;
    }
    return temp ;

}

Node* find_max(Node* root ){
    Node *temp = root ;
    while(temp -> right ){
        temp = temp -> right ;
    }
    return temp ;

}

Node* delete_BST (Node * root , int val ){
    if( root == NULL ) return root ;

    if(root -> data == val ){
        //0child
        if(root -> left == NULL && root -> right == NULL) {
            delete root ;
            return NULL ;
        }
        //1child 
        //left child
        if(root -> left != NULL && root -> right == NULL ){
            Node* temp = root -> left ;
            delete root ;
            return temp ;
        }
        if(root -> left == NULL && root -> right != NULL ){
            Node* temp = root -> right ;
            delete root ;
            return temp ;
        }

        //2 child
        if(root -> left != NULL && root-> right != NULL ){
            int mini = find_min(root -> right) ->data ;
            root -> right = delete_BST(root -> right , mini) ;
            return root ;
        }
    }
    else if(root-> data > val ){
        root -> left = delete_BST(root -> left , val );
        return root ;
    }
    else{
        root -> right = delete_BST(root -> right , val );
        return root ;
    }
}

bool searchInBST(Node *root, int x) {
    // Write your code here.
    if(root == NULL )return false ;

    if(root -> data == x) return true ;
    if(root -> data > x ) return searchInBST(root-> left , x) ;
    else   return searchInBST(root-> right , x) ;
}

int main(){

    Node * root  =NULL; 
    createtree(root) ;
    //8 5 6 4 2 1 7 9  15 12 10 -1 
    cout << "level order traversal " << endl;
    levelOrderTraversal(root) ;

    cout << "\npreorder traversal " << endl;
    PreOrder(root) ;

    cout << "\npostorder traversal " << endl;
    PostOrder(root) ;

    cout << "\ninorder traversal " << endl;
    InOrder(root);

    cout << "\nmin element = "<< find_min(root) -> data<< endl;
    cout << "max element = "<< find_max(root) -> data << endl;


    cout << "\nis present 9 = " << searchInBST(root,9) << endl;

    cout << "enter a val you want to delete." << endl;
    int x ;
    cin >> x ;
    cout << "deleting the value "<< x << endl;
    root = delete_BST(root ,x) ;

    cout << "\nis present 9 = " << searchInBST(root,9) << endl;

    cout << "\ninorder traversal " << endl;
    InOrder(root);



}