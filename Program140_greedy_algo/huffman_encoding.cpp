//p140 -> q7 -> Huffman encoding .
#include<iostream>
#include<bits/stdc++.h>

using namespace std;


// Node class for the Huffman tree
class Node {
public:
    int data; // store data
    Node* left; // left child node
    Node* right; // right child node

    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

// Comparator class for the priority queue
class cmp {
public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data; // compare nodes in priority queue
    }
};

// Traverse function to generate Huffman codes
void traverse(Node* root, vector<string>& ans, string temp) {
    if (root->left == NULL && root->right == NULL) {
        ans.push_back(temp); // reach leaf node, add code
        return;
    }

    traverse(root->left, ans, temp + '0'); // go to left child node
    traverse(root->right, ans, temp + '1'); // go to right child node
}

// Huffman coding function
vector<string> huffmanCodes(string S, vector<int> f, int N) {
    priority_queue<Node*, vector<Node*>, cmp> pq; // create priority queue

    for (int i = 0; i < N; i++) {
        Node* temp = new Node(f[i]); // create new node
        pq.push(temp); // add node to priority queue
    }

    while (pq.size() > 1) {
        Node* left = pq.top(); // get smallest node
        pq.pop();

        Node* right = pq.top(); // get next smallest node
        pq.pop();

        Node* newnode = new Node(left->data + right->data); // create new node
        newnode->left = left; // set left child
        newnode->right = right; // set right child

        pq.push(newnode); // add new node to priority queue
    }

    vector<string> ans;
    string temp = "";

    Node* root = pq.top(); // get root node

    traverse(root, ans, temp); // generate Huffman codes

    return ans;
}

int main() {
    string S = "abcdef";
    vector<int> f = {5, 9, 12, 13, 16, 45};
    int N = f.size();

    vector<string> codes = huffmanCodes(S, f, N);

    for (int i = 0; i < N; i++) {
        cout << S[i] << ": " << codes[i] << endl;
    }

}


