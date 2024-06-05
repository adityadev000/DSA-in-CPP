//p66 -> Construct Tree from Inorder & postorder.
#include<iostream>
#include "tree.cpp"
#include<bits/stdc++.h>

using namespace std;

int Findposition(int in[] ,int inorderStart , int inorderEnd , int element ,int  n){
        for(int i = inorderStart ; i<=inorderEnd ;i++){
            if(in[i]==element){
                return i ; 
            }
        }
        return -1 ;
    }
    Node* solve(int in[],int post[], int &index ,int inorderStart , int inorderEnd , int n){
        if(index>=n || inorderStart>inorderEnd){
            return NULL ;
        }
        
        int element = post[index--] ;
        Node* root  = new Node(element); 
        int position  = Findposition(in , inorderStart , inorderEnd ,element, n);
        
        root->right = solve(in , post , index , position+1 , inorderEnd ,n);
        root->left = solve(in , post , index  , inorderStart , position-1 ,n);
        
        return root ;
        
    }

    //Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int in[], int post[], int n) {
        // Your code here
        int postorderindex  = n-1 ;  
         
         Node* ans = solve(in , post , postorderindex , 0  , n-1 , n );
         return ans ;
    }


int main(){
    int n = 8 ;
    int in[n] =  {4, 8, 2, 5, 1, 6, 3, 7} ;
    int post[n] =  {8, 4, 5, 2, 6, 7, 3, 1};

    Node* ans = buildTree(in , post , n ) ;

    PreOrder(ans ) ; //1 2 4 8 5 3 6 7
    cout  << endl;
    InOrder(ans ) ; //4, 8, 2, 5, 1, 6, 3, 7



}