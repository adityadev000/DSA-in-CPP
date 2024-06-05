//p75  -> q5 ->  Convert BST to Min Heap
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class BinaryTreeNode {
		
	public :
		int data;
		BinaryTreeNode* left;
		BinaryTreeNode* right;

		BinaryTreeNode(int data) {
		this -> left = NULL;
		this -> right = NULL;
		this -> data = data;
		}
	};

void inorder (BinaryTreeNode*& root,vector<int >& in) {
	if( root == NULL )return ;

	inorder(root -> left   ,in);
	in.push_back(root -> data) ;
	inorder(root -> right  ,in);
}
void solve(BinaryTreeNode*& root ,int & i,vector<int > in ) {
	if( root == NULL )return ;

	root -> data = in[i++] ;
	solve(root -> left  ,i ,in);
	solve(root -> right ,i ,in);
}
BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	// Write your code here.
	vector<int > in ;
	inorder (root ,in ) ;

	int i =0 ;
	solve(root ,i ,in);

	return root ;
}

int main(){

    cout << "Alright!!!!!!!!" << endl;


}