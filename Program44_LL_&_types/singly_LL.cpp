//singly linked list ;
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
        int value = this -> data;
        //memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }




    
};
void print (Node* &head){
    Node*temp = head ; 
    while( temp != NULL){
        cout << temp-> data  << " ";
        temp = temp -> next ;
    }
    cout  << endl;
}


void insertAtHead (Node* &head , int d){
    Node * newnode = new Node(d) ;
    newnode -> next = head ;
    head = newnode ;
}

void insertAtTail(Node* &tail , int d) {
    Node * temp = new Node(d) ;
    tail -> next = temp ;
    temp -> next = NULL;
    tail = temp ;
}

void insertAtPosition(Node* &head ,Node*& tail , int position , int d ){
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
        insertAtTail(tail ,d );
        return ;
    }

    Node* newnode= new Node(d) ;
    newnode -> next= temp -> next ;
    temp -> next = newnode ;

}

void deleteAtPosition(Node* &head, int position){
    if(position == 1){
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
int main(){

    Node* node1 = new Node (10);
    // cout << node1-> data << endl;
    // cout << node1-> next << endl;

    Node * head = node1 ; 
    Node * tail  = node1 ; 
/*
    print(head) ;
    insertAtHead(head , 12 ) ;
    insertAtHead(head , 15 ) ;
    print(head) ;
*/
    print(head) ;
    insertAtTail(tail , 12 ) ;
    insertAtTail(tail , 15 ) ;
    print(head) ;


    insertAtPosition(head , tail , 4, 22) ;
    print(head) ;

    deleteAtPosition(head,  4  );
    print(head) ;

}