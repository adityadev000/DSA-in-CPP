//p55 -> q6 ->  Sort a Stack
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

void insertsorted(stack<int> &stack ,int num ){
	if(stack.empty() || (!stack.empty() && stack.top() < num)  ){
		stack.push(num) ;
		return ;
	}
	int x = stack.top() ;
	stack.pop() ;
	insertsorted(stack,num);
	stack.push(x) ;
}

void sortStack(stack<int> &stack)
{
	//base case 
	if(stack.empty()){
		return ;
	}

	int num = stack.top() ;
	stack.pop() ;
	sortStack(stack) ;
	insertsorted(stack ,num );
}

int main(){

    stack<int> s ;
    s.push(45);
    s.push(12);
    s.push(78);
    print(s); 

    sortStack(s) ;
    print(s) ;


}