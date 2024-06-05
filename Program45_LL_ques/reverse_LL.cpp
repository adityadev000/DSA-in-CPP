//reverse of  a linked list
#include<iostream>
#include "slt.cpp"
#include<bits/stdc++.h>

using namespace std;
//appr1 itrative approach ;
Node *reverseLinkedList(Node * head1) 
{
    // Write your code here
    if(head1 == NULL|| head1 -> next  == NULL) return head1 ;
    Node  * prev = NULL;
    Node  * frwd = NULL;
    Node  * current = head1;

    while (current  != NULL){
        frwd = current -> next ;
        current -> next = prev ;
        prev = current ; 
        current = frwd ;
    }
    return prev ;

}




//prev appr by recursion ;
void solve1 (Node *&head2 ,   Node  *prev,   Node  *current ) {

    if(current == NULL) {
        head2 = prev ;
        return   ;
    } 
        Node * frwd = current -> next ;
        

        solve1(head2, current,frwd) ;
        current -> next = prev ;

}
Node *reverseLinkedList2(Node * head2) 
{
    // Write your code here
    Node  * prev = NULL;
    Node  * current = head2;

    solve1(head2 ,prev, current) ;

    return head2 ;
}



//recursive apporach 2
void solve3 (Node *&head3 ,   Node *prev,   Node *current ) {

    if(current == NULL) {
        head3 = prev ;
        return   ;
    } 
        Node *frwd = current -> next ;
        

        solve3(head3, current,frwd) ;
        current -> next = prev ;

}
Node *reverseLinkedList3(Node *head3) 
{
    // Write your code here

    Node * prev = NULL;
    Node * current = head3;
    solve3(head3 ,prev, current) ;
    return head3 ;


}


int main(){

    Node * head1 = NULL ;
    Node * head2 = NULL ;
    Node * head3 = NULL ;

    insertAtTail(head1 ,3);
    insertAtTail(head1, 5);
    insertAtTail(head1, 6);
    cout << "linked list  = " ;
    print (head1) ;
    Node * ans1 = reverseLinkedList(head1);
    cout << "linked list after reversal = " ;
    print (ans1) ;


    insertAtTail(head2 ,4);
    insertAtTail(head2, 5);
    insertAtTail(head2, 6);
    cout << "linked list  = " ;
    print (head2) ;
    Node * ans2 = reverseLinkedList2(head2);
    cout << "linked list after reversal = " ;
    print (ans2) ;



    insertAtTail(head3 ,3);
    insertAtTail(head3, 8);
    insertAtTail(head3, 6);
    cout << "linked list  = " ;
    print (head3) ;
    Node * ans3 = reverseLinkedList3(head3);
    cout << "linked list after reversal = " ;
    print (ans3) ;


}