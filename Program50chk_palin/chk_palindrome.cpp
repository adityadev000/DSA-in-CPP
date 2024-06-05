//p50 check the given linked list is palindrome or not ;

#include<iostream>
#include"slt.cpp"
#include<bits/stdc++.h>

using namespace std;

Node * getmiddle(Node * head){
    Node* slow = head;
    Node* fast = head -> next ;
    
    while(fast != NULL && fast -> next != NULL) {
        fast = fast-> next ->next ;
        slow = slow -> next ;
    }
    return slow ;
}

Node* reverse (Node* head){
    Node* prev = NULL ;
    Node* curr = head ;
    Node * next = NULL ;
    while(curr != NULL ){
        next= curr -> next ;
        curr -> next = prev ;
        prev= curr ;
        curr = next ;
    }
    return prev ;
}

//Function to check whether the list is palindrome.
bool isPalindrome(Node *head)
{
    Node * middle = getmiddle(head) ;
    Node * temp  = middle -> next ;
    Node * head2= reverse(temp ) ;
    Node* head1 =head ;
    
    while(head2 != NULL) {
        if(head1 -> data != head2 -> data) return false ;
        head1 = head1 -> next ;
        head2 = head2 -> next ;
    }
    return true  ;
    
}

int main(){

    Node* head = NULL ;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 3);
    insertAtTail(head, 2);
    insertAtTail(head, 1);
    cout << isPalindrome(head) << endl;

    Node* head2 = NULL ;
    insertAtTail(head2, 1);
    insertAtTail(head2, 2);
    insertAtTail(head2, 6);
    cout << isPalindrome(head2) << endl;


}