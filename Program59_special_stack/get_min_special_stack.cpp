//p59 -> Design a stack that supports getMin() in O(1) time and O(1) extra space.
#include<iostream>
#include<stack>
#include<bits/stdc++.h>

using namespace std;

class SpecialStack {
    public:
        stack<int> s ;
        int mini ;
     void push(int data) {
        //for first element
        if(s.empty()) {
            s.push(data);
            mini = data;
        }
        else
        {
         	if(data < mini) {
                s.push(2*data - mini);
                mini = data;
            }   
            else
            {
                s.push(data);
            }
        }
    }

 int pop() {
        if(s.empty()){
            return -1;
        }
        
        int curr = s.top();
        s.pop();
        if(curr > mini) {
            return curr;
        }
        else
        {
            int prevMin = mini;
            int val = 2*mini - curr;
            mini = val;
            return prevMin;
        }
    }

    int top() {
       if(s.empty())
            return -1;
        
        int curr = s.top();
        if(curr < mini) {
            return mini;
        }
        else
        {
            return curr;
        }
    }

    int getMin() {
        if(s.empty())
            return -1;
        
        return mini;
    }  
};


int main(){

    SpecialStack st ;
    st.push(5) ;
    st.push(3) ;

    cout << st.getMin() << endl;

    st.push(8) ;
    st.push(2) ;
    cout << st.getMin() << endl;
    st.pop() ;
    cout << st.getMin() << endl;
    st.push(4) ;

}