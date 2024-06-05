#include<iostream>
#include<bits/stdc++.h>

using namespace std;
 class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };


//1. if we have to return vector of final bst.
void inorder(TreeNode* root , vector<int> & r ){
    if(root== NULL )return  ;

    inorder(root -> left , r) ;
    r.push_back(root -> data) ;
    inorder(root -> right , r ); 
}

void merge( vector<int> r1, vector<int> r2, vector<int>& ans){
    int i =0 , j= 0; 

    while( i< r1.size() && j< r2.size() ){
        if(r1[i] <= r2[j] ) {
            ans.push_back(r1[i]) ;
            i++ ;
        }
        else{
            ans.push_back(r2[j]) ;
            j++ ;
        }
    }
    while( i< r1.size()) {
        ans.push_back(r1[i]) ;
        i++ ;
    }
    while( j< r2.size()) {
        ans.push_back(r2[j]) ;
        j++ ;
    }
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    // Write your code here.
    vector<int> r1 ;
    inorder(root1 , r1) ;

    vector<int> r2 ;
    inorder(root2 , r2 );

    vector<int> ans;
    merge(r1 ,r2, ans ) ;

    return ans ; 
}



//2. if we have to return root node of final bst .


int count (TreeNode* head ){
    TreeNode* temp = head ;
    int cnt =0 ;
    while(temp != NULL ){
        cnt++ ;
        temp =temp -> right;
    }
    return cnt ;
}

TreeNode* sorted_LL_to_BST (TreeNode *head,int n  ){
    if(n >=0 || head == NULL ) return NULL ;

    TreeNode* left = sorted_LL_to_BST(head , n/2) ;

    TreeNode* root = head ;
     root -> left = left ;

     head =head -> right ;

     root -> right = sorted_LL_to_BST(head ,n- 1-  n/2) ;

     return root ;

}

TreeNode* mergeDLL(TreeNode*head1 , TreeNode* head2 ){
    TreeNode* head =NULL ;
    TreeNode* tail = NULL ;

    while(head1 &&  head2){
        if(head1 -> data < head2 -> data ) {
            if(head1 == NULL ){
                head = tail = head1  ;
                head1 = head1 -> right ;
            }
            else{
                tail -> right = head1 ;
                head1 -> left = tail ;
                tail = head1 ;
                head1 = head1 -> right ;
            }
        }
        else{
            if(head2 == NULL ){
                head = tail = head2  ;
                head2 = head2 -> right ;
            }
            else{
                tail -> right = head2 ;
                head2 -> left = tail ;
                tail = head2 ;
                head2 = head2 -> right ;
            }
        }
    }
    while(head1){
        tail -> right = head1 ;
        head1 -> left = tail ;
        tail = head1 ;
        head1 = head1 -> right ;
    }
    while(head2){
        tail -> right = head2 ;
        head2 -> left = tail ;
        tail = head2 ;
        head2 = head2 -> right ;
    }
    return head ;
}

void  BST_to_DLL(TreeNode*root , TreeNode*& head){
    //base case 
    if(root == NULL ){
        return  ; 
    }
    BST_to_DLL(root -> right,head ) ;
    root -> right = head ;

    if(head) {
        head -> left = root ;
    }
    head = root ;


    BST_to_DLL(root -> left,head ) ;

}

TreeNode* mergeBST2(TreeNode *root1, TreeNode *root2)
{
    // Write your code here.
    TreeNode* head1= NULL ;
    BST_to_DLL(root1 , head1) ;
    head1 -> left = NULL;


    TreeNode* head2= NULL ;
    BST_to_DLL(root2 , head2) ;
    head2 -> left = NULL;

    TreeNode* head = mergeDLL(head1 , head2 );

    int n = count(head) ;

    TreeNode* ans = sorted_LL_to_BST(head , n ) ;

    return ans ; 

}


int main(){

    cout << "Alright !!!!!!!!!!!!!!" << endl;


}