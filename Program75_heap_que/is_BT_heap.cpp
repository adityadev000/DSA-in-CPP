//p75  -> q2 -> Is Binary Tree Heap

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int count (struct Node* tree) {
        if(tree == NULL ) return 0 ;
        
        int ans = 1 + count(tree -> left ) + count(tree -> right) ;
        return ans ; 
    }
    bool isCBT(struct Node* tree, int i ,int n ){
        if(tree == NULL )return true ;
        if(i >= n ) return false ;
        else {
            bool left = isCBT(tree -> left , 2*i+1 , n);
            bool right = isCBT(tree -> right , 2*i+2 , n);
            
            return (left && right) ;
        }
    }
    
    bool ismaxheap(struct Node* tree) {
        //leaf node 
        if(tree -> left == NULL && tree -> right == NULL ){
            return true ;
        }
        //one child 
        if(tree -> right == NULL){
            return tree -> data > tree -> left -> data ;
        }
        else{ //2 child 
            return tree -> data > tree -> right -> data && tree -> data > tree -> left -> data&&
                    ismaxheap(tree -> left ) && ismaxheap (tree -> right) ;
        }
    }
    bool isHeap(struct Node* tree) {
        // code here
        int n = count(tree) ;
        int i =0 ;
        if(isCBT(tree , i , n )  && ismaxheap(tree)){
            return true ;
        } 
        else return false ;
    }

int main(){

    cout << "Alright !!!!!!!!!" << endl;


}