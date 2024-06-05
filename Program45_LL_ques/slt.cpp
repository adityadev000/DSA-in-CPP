//singly linked list header file ;
#include<iostream>

using namespace std;

class Node {
public : 
    int data ; 
    Node* next ; 


    Node (int data ) {
        this -> data  = data ;
        this ->  next = NULL ; 
    } 

    //destructor ;
     ~Node() {
        // int value = this -> data;
        //memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        // cout << " memory is free for node with data " << value << endl;
    }




    
};
void print (Node* &head){
    if(head == NULL) cout << "list is empty !!!!";
    Node*temp = head ; 
    while( temp != NULL){
        cout << temp-> data  << " ";
        temp = temp -> next ;
    }
    cout  << endl;
}


void insertAtHead (Node* &head , int d){
    Node * newnode = new Node(d) ;
    if(head == NULL) {
        newnode -> next = NULL ;
        head = newnode ;
    }
    else{
        newnode -> next = head ;
        head = newnode ;
    }
    
}

void insertAtTail(Node* &head , int d) {
    Node * temp = new Node(d) ;
    if(head == NULL) {
        temp -> next = NULL ;
        head = temp  ;
    }
    else {
        Node* find = head ;
        while(find-> next != NULL) find = find -> next ;
        

        find -> next = temp ;
        temp -> next = NULL;
        find = temp ;
    }
}

void insertAtPosition(Node* &head , int position , int d ){
    //assuming position is valid position
    //insert at start 
    if(position == 1 ){
        insertAtHead(head ,d );
        return ;
    }
    //move to n-1 position ;
    int cnt =1 ; 
    Node* temp  = head ;
    while (cnt < position -1) {
        temp = temp -> next ;
        cnt ++ ;
    }
    //insert at end 
    if( temp -> next == NULL){
        insertAtTail(head ,d );
        return ;
    }

    Node* newnode= new Node(d) ;
    newnode -> next= temp -> next ;
    temp -> next = newnode ;

}

void deleteAtPosition(Node* &head, int position){
    if(head == NULL) cout << "list is empty !!!!" << endl;
    else if(position == 1){
        Node * current = head;
        head = head -> next ;
        current -> next = NULL ;
        delete current ;
    }
    else {
        Node* pre = NULL ;
        Node* current = head ;
        int cnt = 1 ;
        while (cnt < position){
            pre = current ;
            current= current-> next ;
            cnt++ ;
        }
        pre -> next = current -> next ;
        current-> next = NULL ;
        delete current ;

    }
}
