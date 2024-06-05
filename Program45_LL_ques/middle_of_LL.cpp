//find middle of  a linked list ;
#include<iostream>
#include "slt.cpp"
#include<bits/stdc++.h>

using namespace std;

Node *findMiddle(Node *head) {
    
    if((head == NULL) || (head-> next == NULL)) return head ;


        Node* fast = head -> next ;
        Node * slow = head ;

        while(fast != NULL){
            fast = fast -> next ;
            if(fast  != NULL) 
            fast = fast -> next ;

            slow = slow -> next ;
        }
    return slow ;
}

int main(){

    Node * head = NULL ;
    insertAtTail(head ,3);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 9);
    cout << "linked list  = " ;
    print (head) ;
    Node * ans = findMiddle(head);

    cout << "midlle = " << ans -> data << endl;


}