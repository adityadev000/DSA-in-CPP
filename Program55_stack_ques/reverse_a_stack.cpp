//p55 -> q5 -> Reverse Stack Using Recursion.
#include<iostream>
#include<stack>

using namespace std;

void print (stack<int> s) {
    while(!s.empty()) {
        cout <<  s.top() << " " ;
        s.pop() ;
    }
    cout << endl;
}

void insertbottom (stack<int>& myStack, int x) {

    //base case.
    if(myStack.empty()){
        myStack.push(x) ;
        return ;
    }

    int num = myStack.top() ;
    myStack.pop() ;
    insertbottom( myStack,  x) ;
    myStack.push(num) ;

}

void reverseStack(stack<int> &stack) {
    //base case
    if(stack.empty()) {
        return ;
    }


    int num = stack.top() ;
    stack.pop() ;
    reverseStack(stack) ;
    insertbottom( stack , num) ;

}

int main(){

    stack<int> s ;
    s.push(4);
    s.push(6);
    s.push(7);
    print(s); 

    reverseStack(s) ;
    print(s) ;


}