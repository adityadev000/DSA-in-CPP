//p55 -> q4 -> Insert An Element At Its Bottom In A Given Stack.
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

void solve (stack<int>& myStack, int x) {

    //base case.
    if(myStack.empty()){
        myStack.push(x) ;
        return ;
    }

    int num = myStack.top() ;
    myStack.pop() ;
    solve( myStack,  x) ;
    myStack.push(num) ;

}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    solve( myStack,  x) ;
    return myStack;
    
    
}

int main(){

    stack<int> s ;
    s.push(4);
    s.push(6);
    s.push(7);
    print(s); 

    stack<int> ans = pushAtBottom(s , 14);
    print(ans) ;


}