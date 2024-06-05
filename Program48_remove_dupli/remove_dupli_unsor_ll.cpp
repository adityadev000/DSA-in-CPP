#include<iostream>
#include "slt.cpp"
#include<bits/stdc++.h>

using namespace std;

Node *removeDuplicates(Node *head)
{
    if(head == NULL)
        return NULL;
    
    unordered_map<int , bool> visited;
    Node* current = head;
    Node* prev = NULL;
    Node* temp = NULL;


    while(current != NULL){
        if(visited[current->data] == true){
            temp = current;
            prev -> next = current -> next;
            current = current -> next;
            delete temp;
        }
        else{
            visited[current->data] = true;
            prev = current;
            current = current -> next;
        }
    }


    return head;
}

int main(){

    Node* head = NULL ;
    insertAtTail(head , 5);
    insertAtTail(head , 4);
    insertAtTail(head , 5);
    insertAtTail(head , 4);
    insertAtHead(head,3);

    Node* ans = removeDuplicates(head) ;
    print(ans) ;


}