//p49 Merge Two Sorted Linked Lists 
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Node {
public : 
    int data ; 
    Node* next ; 
};

Node* solve (Node* first, Node* second) {
//one node in first linked list 
    if(first -> next == NULL){
        first-> next = second ;
        return first ;
    }

//creating pointers.
    Node* curr1  = first ;
    Node* next1  = curr1 -> next  ;
    Node* curr2  = second ;
    Node* next2  = curr2 -> next  ;

//process to insert node of second in first
    while(next1 != NULL && curr2 != NULL ) {
        //right place to insert. 
        if(curr2 -> data >= curr1-> data  && curr2 -> data <= next1 -> data){ 
            curr1-> next = curr2 ; 
            next2= curr2-> next ; //placing a pointer on curr2-> next so that we cant lost it.
            curr2 -> next = next1 ; 

        //arranging pointers
            curr1= curr2; 
            curr2 = next2 ;
        }
        else{
        // wrong place to insert skip.
            curr1 = next1 ;
            next1 = next1 -> next ;

            //first is finished so simply connect the last node to second ka curr se.
            if(next1 == NULL) {
                curr1 -> next = curr2;
                return first ;
            }
        }
    }
    return first ;
}

Node* sortTwoLists(Node* first, Node* second)
{
    if(first == NULL) return second ;
    if(second == NULL) return first ;

    //jiska head ka data chhota hoga whi first bnega taki proper insert ho paye .
    if(first-> data <= second ->data){
        return solve(first ,second) ;
    }
    else{
        return solve(second ,first ) ;
    }
}


int main(){

    
    cout << "Alright !!!!!!!" << endl;

}