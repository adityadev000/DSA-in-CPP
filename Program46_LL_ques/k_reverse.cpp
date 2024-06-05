//reverse node of linked list in group of k ; 
#include<iostream>
#include "slt.cpp"
#include<bits/stdc++.h>

using namespace std;

int getlength(Node*head){
    int c=0;
    while(head!=NULL){
        c++;
        head=head->next;

    }
    return c;

}
Node* kReverse(Node* head, int k) {
    //base case 
    if(head == NULL) return NULL ;

    //reverse 1 case ;
    int cnt = 0 ;
    Node* prev = NULL;
    Node* curr = head;
    Node* next  = NULL;

    while ( curr != NULL && cnt < k  ){
        next = curr -> next ;
        curr -> next = prev ;
        prev = curr ;
        curr = next ;
        cnt ++ ;
    }

    //recursive call ;
    if(next != NULL) {
        //head -> next = kReverse(next , k) ; 
        if(getlength(next  ) >= k ){
            head -> next = kReverse(next , k) ; 
        }
        else {
            head-> next = next ;
        }
    }
        return prev;
}

int main(){
    Node * head = NULL ;
    insertAtTail(head , 12 ) ;
    insertAtTail(head , 15 ) ;
    insertAtTail(head , 56 ) ;
    insertAtTail(head , 23 ) ;
    insertAtTail(head , 34 ) ;
    insertAtTail(head , 5 ) ;


    Node* ans = kReverse(head , 4 ) ;
    print(ans) ;


}