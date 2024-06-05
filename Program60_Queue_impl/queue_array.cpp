//p60 -> queue implementation using array.
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Queue {
public:
    int *arr ;
    int size ;
    int qfront ;
    int rear ;
    Queue(int n ) {
        // Implement the Constructor
        size = n ;
        arr = new int[size] ;
        qfront = 0 ;
        rear =0 ;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(qfront == rear ) return true ;
        return false ;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(rear == size) return ;

        arr[rear] = data ;
        rear ++ ;
    }

    int dequeue() {
        // Implement the dequeue() function
        if(isEmpty()) return -1 ;
        int val = arr[qfront ] ;
        arr[qfront]= -1 ;
        qfront ++ ;
        return val ;
    }

    int front() {
        // Implement the qfront() function
        if(isEmpty()) return -1 ;
        return arr[qfront]  ;
    }
};

int main(){

    Queue myq (4) ;
    myq.enqueue(3);
    myq.enqueue(4);
    myq.enqueue(5);

    cout << "front = " << myq.front() << endl ;

    cout << myq.dequeue() <<endl ;
    cout << "front = " << myq.front() << endl ;


}