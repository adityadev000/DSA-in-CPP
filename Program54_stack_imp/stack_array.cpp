#include<iostream>
#include<stack>

using namespace std;

class Stack {
    int *arr ;
    int top ;
    int size ;
public :

    Stack(int s ) {
        this -> size = s ;
        this-> top = -1 ;
        arr = new int[s] ;
    }

    void push (int d ) {
        if(size - top >1 ){
            top ++ ;
            arr[top] = d ;
        }
        else cout << "Stack overflow" << endl;
    }

    int pop (){
        if (top == -1 ){
            cout << "Stack underflow" << endl;
            return -1 ;
        }
        else {
            int ans = arr[top] ;
            top-- ;
            return ans ;
        }
    }

    int peek() {
        if( top == -1){
            return -1 ;
        }
        return arr[top];
    }

    bool isEmpty() {
        if( top == -1) {
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){

    Stack st(5);

    st.push(22);
    st.push(43);
    st.push(44);
    st.push(22);
    st.push(43);
    st.push(44);

    cout << st.peek() << endl;

    st.pop();

    cout << st.peek() << endl;

    st.pop();

    cout << st.peek() << endl;

    st.pop();

    cout << st.peek() << endl;

    if(st.isEmpty()) {
        cout << "Stack is Empty mere dost " << endl;
    }
    else{
        cout << "Stack is not Empty mere dost " << endl;
    }

/*
    //creation of stack
    stack<int> s;

    //push operation
    s.push(2);
    s.push(3);

    //pop
    s.pop();

    cout << "Printing top element " << s.top() << endl;

    if(s.empty()){
        cout << "Stack is empty " << endl;
    }
    else{
        cout << "stack is not empty " << endl;
    }

    cout << "size of stack is " << s.size() << endl;

    */

    return 0;


}