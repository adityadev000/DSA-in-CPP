//p66 -> Construct Tree from Inorder & Preorder.
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
    Node* solve(int in[],int pre[], int &index ,int inorderStart , int inorderEnd , int n){
        if(index>=n || inorderStart>inorderEnd){
            return NULL ;
        }
        
        int element = pre[index++] ; // At every interation index is increasing
        Node* root  = new Node(element); 
        int position  = Findposition(in , inorderStart , inorderEnd ,element, n);
        
        root->left = solve(in , pre , index  , inorderStart , position-1 ,n);
        root->right = solve(in , pre , index , position+1 , inorderEnd ,n);
        
        return root ;
        
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
         int preorderindex  = 0 ;  //Pre order is NLR so First element is root .
         
         Node* ans = solve(in , pre , preorderindex , 0  , n-1 , n );
         return ans ;
    }

int main(){
    int n = 6 ;
    int in[n] =  {3, 1 ,4 ,0, 5, 2} ;
    int pre[n] =  {0 ,1 ,3,4, 2,5} ;

    Node* ans = buildTree(in , pre , n ) ;

    PostOrder(ans ) ; //3 4 1 5 2 0
    cout  << endl;
    InOrder(ans ) ; //3, 1 ,4 ,0, 5, 2



}