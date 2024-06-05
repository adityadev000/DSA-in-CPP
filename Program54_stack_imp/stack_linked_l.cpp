#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Stack ; //forward declaration 

class Node {
    int data ;
    Node* next ;

    friend class Stack ; //making stack friens to Node.

    public :
    Node (int d ){
        this -> data = d ;
        this -> next = NULL ;
    }
};

class Stack {
    Node* top ;
 
public :

Stack() : top (NULL)  {} //intialisation list. 

void push (int data){
    Node * temp = new Node(data) ;
    if(top == NULL ) {
        top = temp ;
    }
    else{
        temp -> next = top ;
        top = temp ;
    }
}

int pop (){
    if(top != NULL ){
        Node * temp = top ;
        top = top -> next ;

        int ans = temp -> data ;
        delete temp ;
        return ans ;
    }
    else{
        cout << "stack underflow " << endl;
        return -1 ;
    }
}

int peek () {
    if(top != NULL ){
        return top -> data ;
    }
    return -1 ;
}

bool isEmpty(){
    if(top  == NULL ) return 1 ;
    return 0 ;
}

};

int main(){

    Stack st ;
    cout <<st.isEmpty()  << endl; //1

    st.push(22);
    st.push(43);
    st.push(44);

    cout <<st.isEmpty()  << endl; //0

    cout << st.peek() << endl; // 44

    st.pop();

    cout << st.peek() << endl; //43

    st.pop();

    cout << st.peek() << endl; //22

    st.pop();

    cout << st.peek() << endl; //-1

}