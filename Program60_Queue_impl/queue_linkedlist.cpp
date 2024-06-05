//p60 -> queue implementation using linked list.
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
class Queue ;

class Node {
public : 
    friend class queue ;
    int data ; 
    Node* next ; 


    Node (int data ) {
        this -> data  = data ;
        this ->  next = NULL ; 
    } 
};

class Queue  {
    Node* front ;
    Node * rear ;

public :
    Queue () {
        front = NULL ;
        rear = NULL ;
    }

    void enqueue(int x ){
        Node * temp = new Node(x) ;
        if(front == NULL){
            front = rear = temp ;
        }
        else {
            rear -> next = temp ;
            rear = temp ;
        }
    }

    int dequeue (){
        Node * temp = front ;
        front = front -> next ;
        int ans = temp -> data ;

        delete temp ;

        return ans  ;
    }

    int getFront(){
        if(isEmpty() ) return -1 ;
        return front -> data ;
    }
    int getRear(){
        if(isEmpty() ) return -1 ;
        return rear -> data ;
    }

    bool isEmpty() {
        if(front == NULL ) return 1 ;
        return 0 ; 
    }
};


int main(){

    Queue q ;

    q.enqueue(5) ;
    q.enqueue(6) ;
    q.enqueue(7) ;

    cout << "front =  " << q.getFront() << endl;  //5
    cout << "front =  " << q.getRear() << endl; //7

    q.enqueue(8) ;
    q.enqueue(10) ;
    
    cout << "front =  " << q.getFront() << endl; //5
    cout << "front =  " << q.getRear() << endl; //10

    q.dequeue() ; //5
    q.dequeue() ;//6

    cout << "front =  " << q.getFront() << endl; //7
    cout << "front =  " << q.getRear() << endl; //10

    cout << "empty -> " <<  q.isEmpty() << endl;


}