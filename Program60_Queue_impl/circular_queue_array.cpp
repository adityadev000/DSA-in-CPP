//p60 -> circular queue implemntation using array.
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class CircularQueue{
    public:
    int *arr ;
    int size ;
    int front ;
    int rear ;
    // Initialize your data structure.
    CircularQueue(int n){
        // Write your code here.
        size= n ;
        arr= new int[size] ;
        front = -1;
        rear = -1 ;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        // Write your code here.
        if((front == 0 && rear == size-1) ||( rear == (front-1 )% (size-1)) ) {
            return false ;
        }
        else if (front == -1)  {//first enqueue 
            front = rear = 0 ;
        } 
        else if(rear == size -1) rear = 0 ;
        else rear ++ ;

        arr[rear] = value ;
        return true ;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // Write your code here.
        if(front == -1) return -1 ;

        int ans = arr[front] ;
        if (front == rear ){
            front = rear = -1 ;
        }
        else if (front == size-1 ){
            front =0 ;
        }else{
            front ++ ;
        }
        return ans  ;
    }
};

int main(){

    CircularQueue myq(5) ;

    cout << myq.enqueue(4) << endl ;
    cout << myq.enqueue(5) << endl ;
    cout << myq.enqueue(6) << endl ;

    cout << myq.dequeue() << endl;

}