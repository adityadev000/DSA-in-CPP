//p70 -> q3 ->    Predecessor And Successor In BST
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        
        TreeNode(int x) {
            this -> data = x ;
            this -> left = NULL ;
            this -> right = NULL ;
        }
        
    };
pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{

    TreeNode* temp = root ;
    int pred = -1 ;
    int succ = -1 ;
    //find node.
    while((temp  -> data != key)  ){
        if(temp -> data > key ){
            succ = temp -> data;
            temp =temp -> left ;
        }
        else{
            pred = temp -> data;
            temp =temp -> right ;
        }
        if(temp == NULL ){
            break ;
        }
    }
    if(temp != NULL ){

            TreeNode* left_tree = temp-> left ;
            while (left_tree!= NULL ){
                pred= left_tree -> data;
                left_tree = left_tree -> right;
            }


            TreeNode* right_tree = temp-> right ;
            while (right_tree!= NULL ){
                succ = right_tree -> data;
                right_tree = right_tree -> left ;
            }
    }
    pair<int, int > ans = make_pair(pred ,succ) ;
    return ans ;
}
int main(){
    TreeNode* root = new TreeNode (65) ;
    TreeNode* rl = new TreeNode (56) ;
    TreeNode* rr = new TreeNode (92) ;
    TreeNode* rll = new TreeNode (43) ;
    TreeNode* rrl = new TreeNode (90) ;

    root -> left = rl ;root -> right =rr ; rl -> left  = rll ;rr -> left = rrl ;

    pair<int, int > ans = predecessorSuccessor(root ,96) ;
    cout << ans.first << endl;
    cout << ans.second << endl;


}