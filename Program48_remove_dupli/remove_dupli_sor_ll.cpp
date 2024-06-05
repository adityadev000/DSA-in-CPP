#include<iostream>
#include "slt.cpp"
#include<bits/stdc++.h>

using namespace std;

Node * removeDuplicates(Node *head)
{
    if(head == NULL) return head ;
    Node* curr = head  ; 
    while (curr -> next != NULL && curr != NULL){
        if(curr -> data != curr-> next -> data){
            curr= curr -> next ;
        }
        else{
            Node* temp  = curr -> next   ;
            curr -> next = curr -> next -> next ;
            delete temp ;
        }
    }
    return head ;
}

int main(){


    Node* head = NULL ;
    insertAtTail(head , 3);
    insertAtTail(head , 4);
    insertAtTail(head , 4);
    insertAtTail(head , 5);
    insertAtHead(head,3);

    Node* ans = removeDuplicates(head) ;
    print(ans) ;

    cout << "alright!!!!!!" << endl;
}