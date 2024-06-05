//detect and remove loop coding ninjas ;  -> 
/*https://www.naukri.com/code360/problems/interview-shuriken-42-detect-and-remove-loop_
241049?leftPanelTab=0%3Fsource%3Dyoutube&campaign=YouTube_codestudio_lovebabbar28thjan   */

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Node {
public : 
    int data ; 
    Node* next ; 
};



Node *  floydsCycle(Node* head) {
    if(head == NULL ) return NULL ;

    Node * slow = head ;
    Node * fast  = head ;

    while (slow !=  NULL && fast != NULL  ){
        fast = fast -> next ;
        if(fast != NULL) fast = fast -> next ;

        slow = slow -> next ;


        if(slow == fast ) return slow ;
    }
    return NULL ;
}

Node * getStartingNode(Node * head ) {
if(head == NULL ) return NULL ;

    Node* intersection = floydsCycle(head) ;
    if(intersection == NULL ) return NULL;

        Node* slow = head ;
        while (slow != intersection ) {
            slow = slow -> next ;
            intersection = intersection -> next ;
        }
        return slow ;
}

Node* removeLoop(Node* head ){
    if(head == NULL ) return NULL ;
    Node* start  = getStartingNode(head) ;
    Node* temp = start ;

    if(start == NULL ) return head  ;
    else {
        while(temp -> next !=start ) temp = temp -> next ;
    }
    temp -> next  =NULL ;

    return head ;
}


int main(){

    cout << "Alright !!!!!!!!!!!!!!!" << endl ;


}