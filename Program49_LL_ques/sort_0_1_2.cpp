//p49 Sort 0's ,1's ,2's in the linke list
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Node {
public : 
    int data ; 
    Node* next ; 


    Node (int data ) {
        this -> data  = data ;
        this ->  next = NULL ; 
    } 
};

void insertAtTail (Node* &tail , Node* temp ){
    tail -> next = temp ;
    tail = temp ;
}

Node* sortList(Node *head){
    if(head == NULL || head-> next ==NULL) {
        return head ;
    }
    Node* zerohead = new Node(-1) ;
    Node* zerotail = zerohead ;
    Node* onehead = new Node(-1) ;
    Node* onetail = onehead ;
    Node* twohead = new Node(-1) ;
    Node* twotail = twohead ;

    Node * temp = head ;
    //store 0,1,2 in new linked list.
    while(temp != NULL) {
        if(temp -> data == 0)
            insertAtTail(zerotail ,temp) ;
        else if(temp -> data == 1)
            insertAtTail(onetail , temp) ;
        else
            insertAtTail(twotail , temp) ;
        temp = temp->next ;
    }

    //merge these 3 linked list.
    if(onehead -> next != NULL){
        zerotail -> next = onehead->next ;
    }
    else{
        zerotail -> next = twohead->next ;
    }

    onetail-> next = twohead->next ;
    twotail-> next = NULL ;

    //set head
    head= zerohead->next ;

    //delete extra nodes.
    delete zerohead;
    delete onehead;
    delete twohead;

    return head ;

}

int main(){

    cout << "Alright" << endl;


}