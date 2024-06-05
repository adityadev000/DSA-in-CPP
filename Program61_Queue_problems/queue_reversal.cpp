//p61 -> q1 -> queue revrsal.
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void solve (queue<int>& q){
    //base case 
    if(q.empty() )return ;
    
    int element = q.front() ;
    q.pop() ;
    
    solve(q) ;
    
    q.push(element) ;
}

queue<int> rev(queue<int> q)
{
    
    solve(q) ;
    
    return q ;
    
}

int main(){

    queue<int>q ;
    for(int i =1 ; i<= 4 ; i++){
        q.push(i*2) ;
    }
    cout << q.front() << endl; //2 4 6 8
    q = rev(q) ;
    cout << q.front() << endl; // 8 6 4 2

 

}