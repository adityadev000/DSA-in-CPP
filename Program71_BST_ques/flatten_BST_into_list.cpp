//p71 -> q2 -> flat a BST into list.
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

 template <class T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

void solve(TreeNode<int>* root, vector<int> &ans){

    if(root == NULL) return;

    solve(root->left, ans);
    ans.push_back(root->data);
    solve(root->right, ans);

}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<int> ans;
    solve(root, ans);
   

    TreeNode<int>* head = NULL;
    TreeNode<int>* tail = head;

    for(int i = 0; i < ans.size(); i++){

        if(head == NULL){
            TreeNode<int>* newNode = new TreeNode<int>(ans[i]);
            head = newNode;
            tail = newNode;
        }
        else{
        TreeNode<int>* newNode = new TreeNode<int>(ans[i]);
        tail->right = newNode;
        tail = newNode;

        }

    }

    return head;

}

int main(){

    cout << "Alright!!!!!!!" << endl;


}