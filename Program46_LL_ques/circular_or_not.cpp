#include<iostream>
#include<bits/stdc++.h>

using namespace std;
class Node {
    public:
    int data;
    Node* next;

    //constrcutor
    Node(int d) {
        this->data = d;
        this->next = NULL;
    }

};

void insertNode(Node* &tail, int element, int d) {
    

    //empty list
    if(tail == NULL) {
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
    }
    else{
        //non-empty list
        //assuming that the element is present in the list

        Node* curr = tail;

        while(curr->data != element) {
            curr = curr -> next;
        }
        
        //element found -> curr is representing element wala node
        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;

    }

}    

bool isCircular(Node * head ) {
    if(head == NULL || head -> next == head ) 
        return true ; 
    
    if(head -> next = head ) return 0 ;

    else{
        Node* temp = head -> next  ;
        while (( temp != NULL) && (temp != head)  ) {
            temp = temp -> next ;
        }
        if (temp == NULL )return false ;
        if (temp == head )return true  ;
    }
}

int main(){

    Node*tail = NULL ;
    insertNode(tail, 5, 3);
    insertNode(tail, 3, 5);
    insertNode(tail, 5, 7);
    insertNode(tail, 7, 9);
    insertNode(tail, 5, 6);
    insertNode(tail, 9, 10);
    insertNode(tail, 3, 4);

    if(isCircular){
        cout << "circular" << endl;
    }
    else{
        cout << "not circular " << endl;
    }

}