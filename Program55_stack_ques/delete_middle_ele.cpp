////p55 -> q2 ->Delete middle element from stack
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

void solve(stack<int>&inputStack, int count, int N) {
    //base case
    if(count == N/2) {
        inputStack.pop();
        return ;
    }
    
    int num = inputStack.top();
    inputStack.pop();
    
	//RECURSIVE CALL
    solve(inputStack, count+1, N);
    
    inputStack.push(num);
    
}

void deleteMiddle(stack<int>&inputStack, int N){
	
  	int count = 0;
    solve(inputStack, count, N);
   
}

int main(){

    stack<int> s ;
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);
    print(s) ;

    deleteMiddle(s , 4) ;
    print (s) ;

}