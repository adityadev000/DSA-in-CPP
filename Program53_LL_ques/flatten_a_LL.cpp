#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
        int data;
        Node * next;
        Node * child;
        Node(int data){
            this->data=data;
            this->next=NULL;
            this->child =NULL ;
        }
};

Node* merge (Node* head1 ,Node* head2 ){
	
    if(head1 == NULL)
        return head2;
    
    if(head2 == NULL)
        return head1;


    //creating adummy Node.
    Node * ans = new Node (-1) ;
    Node * temp = ans ; 
    while (head1 != NULL && head2 != NULL ) {
        if (head1 -> data  < head2 ->  data ){
            temp -> child = head1 ;
            temp = head1 ;
            head1 = head1-> child ; 
        }
        else {
             temp -> child = head2 ;
            temp = head2 ;
            head2 = head2-> child ; 
        }
    }
    while (head1 != NULL) {
        temp ->child = head1 ;
        temp = head1 ;
        head1 = head1->child ; 
    }
    while (head2  != NULL ){
        temp ->child = head2 ;
        temp = head2 ;
        head2 = head2->child ; 
    }
    return ans ->child ;

}

Node* flattenLinkedList(Node* head) 
{

	if(  head -> next == NULL ){
		return head ;
	}

	Node * head1  = head ;
	Node* head2 = flattenLinkedList (head -> next) ;
	head1 -> next = NULL ;
	Node * ans = merge (head1 ,head2 ) ;

	return ans ;
}

int main(){

    cout << "Alright!!!!!!!!!!!!" << endl;


}