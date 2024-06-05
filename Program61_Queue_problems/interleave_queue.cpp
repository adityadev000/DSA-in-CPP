//p61 -> Q6 -> Interleave the First Half of the Queue with Second Half.
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int> rearrangeQueue(queue<int> &q){
    stack <int> s ;
    vector<int> ans  ;
    int mid = q.size() /2 ;
    for(int i = 0; i< mid ;i++ ){
        int val = q.front() ;
        q.pop() ;
        s.push(val) ;
    }
    while(!s.empty() ){
        int val = s.top() ;
        s.pop() ;
        q.push(val) ;
    }
    for(int i = 0; i< mid ;i++ ){
        int val = q.front() ;
        q.pop() ;
        q.push(val) ;
    }
    for(int i = 0; i< mid ;i++ ){
        int val = q.front() ;
        q.pop() ;
        s.push(val) ;
    }
    while(!s.empty() ){
        int val = s.top() ;
        s.pop() ;
        q.push(val) ;
        
        val = q.front() ;
        q.pop() ;
        q.push(val) ;
        
    }
    for(int i =0 ; i< 2*mid ;i ++ ){
        int val = q.front() ;
        q.pop() ;
        ans.push_back(val) ;
    }
    return ans ;
}
int main(){

    queue<int>q ;
    for(int i =1 ; i<= 6 ; i++){
        q.push(i*2) ;
    }
    cout << q.front() << endl; //2 4 6 8 10 12
    vector<int> a = rearrangeQueue(q) ;
    
    for(int i = 0; i< a.size() ; i++){
        cout << a[i] << " " ;
    }
    cout  << endl;



}