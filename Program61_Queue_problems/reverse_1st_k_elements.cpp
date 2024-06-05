//p61 -> q3- >Reverse First K elements of Queue

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

//Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        // add code here.
        stack <int> s ;
        for(int i = 0; i< k ; i++ ){
            int val = q.front();
            q.pop() ;
            s.push(val) ;
         }
         for(int i = 0; i< k ; i++ ){
            int val = s.top();
            s.pop() ;
            q.push(val) ;
         }
         int n= q.size() ;
         for(int i =0 ;i < n-k ;i ++ ){
             int val = q.front() ;
             q.pop() ;
             q.push(val) ;
         }
         return q ;
         
    }
 
 int main(){
 
    queue<int>q ;
    for(int i =1 ; i<= 5 ; i++){
        q.push(i*2) ;
    }
    cout << q.front() << endl; //2 4 6 8 10
    q = modifyQueue(q ,3 )  ;
    cout << q.front() << endl; // 6 4 2 8 10

 
 
 }     