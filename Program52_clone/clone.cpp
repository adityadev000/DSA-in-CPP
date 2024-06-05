//p52 make clone of a linked list.
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Node {
public : 
    int data ; 
    Node* next ; 
    Node* arb ; 


    Node (int data ) {
        this -> data  = data ;
        this ->  next = NULL ; 
    } 
};



// P52a -> Approach -> 222222222222222222
void insertAttail(Node *&clonehead ,Node *&clonetail ,int d ){
    Node* temp = new Node (d) ;
    if(clonehead == NULL ){
        clonehead = temp ;
        clonetail = temp;
    }
    clonetail -> next = temp ;
    clonetail = temp ;
}
Node *copyList(Node *head)
    {
        Node* clonehead = NULL ;
        Node * clonetail = NULL ;
        Node* temp = head ;
        //step1 -> creating clone.
        while(temp != NULL ){
            insertAttail(clonehead ,clonetail ,temp -> data );
            temp = temp -> next ;
            
        }
        
    //store mapping.
        Node* originalnode= head ;
        Node* clonenode = clonehead ;
        unordered_map <Node * ,Node* > mapoldTOnew ;
        while(originalnode != NULL ){
            mapoldTOnew [originalnode] = clonenode ;
            originalnode = originalnode -> next ;
            clonenode= clonenode-> next ;
        }
        
    //link random pointers.
        originalnode= head ;
        clonenode = clonehead ;
        while(clonenode != NULL ){
            clonenode -> arb  =  mapoldTOnew[originalnode -> arb] ;
            originalnode = originalnode -> next ;
            clonenode= clonenode-> next ;
        }
        return clonehead ;
    }



//P52b -> Approach -> 33333333333333333333
Node *copyList(Node *head , int x = 1 )
    {
        Node * temp = head;
        while(temp!=NULL){
            Node * clonenode = new Node(temp->data);
            clonenode->next=temp->next;
            temp->next=clonenode;
            temp=temp->next->next;
        }
        temp=head;
        while(temp!=NULL){
            if(temp->arb)
                temp->next->arb=temp->arb->next;
                temp=temp->next->next;
        }
        temp=head;
        Node * clonehead=head->next;
        while(temp->next!=NULL){
            Node * next  = temp->next;
            temp->next=temp->next->next;
            temp=next ;
        }
        return clonehead;
    }
int main(){

    
cout << "alright !!!!!!!!!!" << endl;

}