//p51 Add two numbers represented by a linked list. 
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
class Node {
public : 
    int data ; 
    Node* next ; 

    
    Node (int data ) {
        this -> data  = data ;
        this ->  next = NULL ; 
    } 
}; 


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

void insertATtail(Node*& head, Node* &tail ,int val ){
    Node* temp = new Node (val) ;
    if(head == NULL ){
        head = temp ;
        tail = temp ;
    }
    else{
        tail -> next =  temp ;
        tail = temp ;
    }
}

Node* add(Node* num1, Node* num2){
    int carry = 0 ;
    Node * anshead= NULL ;
    Node* anstail = NULL ;
    
    while(num1 != NULL || num2 != NULL || carry != 0) {
        int val1 = 0 ,val2 =0 ;
        if(num1 != NULL ){
            val1 = num1 -> data;
        }
        if(num2 != NULL ){
            val2 = num2 -> data;
        }
        
        int sum = carry + val1 + val2 ;
        int digit = sum % 10 ;
        
        insertATtail(anshead,anstail , digit) ;
        carry = sum /10 ;
        
        if(num1 != NULL) num1 = num1-> next ;
        if(num2 != NULL) num2 = num2 -> next ;
    }
    return anshead ;
}


    //Function to add two numbers represented by linked list.
    Node* addTwoLists(Node* num1, Node* num2)
    {
        
//modify num1 & and num2 removing leading zeros
        while(num1 -> next != NULL && num1-> data == 0 ){
            Node* temp = num1 ;
            num1 = num1 -> next ;
            delete temp ;
        }
        
        while(num2 -> next != NULL && num2-> data == 0 ){
            Node* temp = num2 ;
            num2 = num2 -> next ;
            delete temp ;
        }
        
        //step1 reverse both linked list 
        num1 = reverse(num1) ;
        num2 = reverse(num2) ;
        
        //add both ll
        Node* ans = add(num1,num2);
        
        //reverse again to get final ans 
        ans = reverse(ans) ;
        return ans ;
        
    }



int main(){

    
    cout << "Alright!!!!gfg " << endl;

}