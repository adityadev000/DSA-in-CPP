//p75  -> q4 -> Minimum Cost of ropes
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long , vector<long long> , greater<long long> > pq ;
        for(int i =0; i< n ;i ++ ){
            pq.push(arr[i]) ;
        }
        long long ans  =0 ;
        while( pq.size() > 1  ){
            long long a= pq.top() ;
            pq.pop();
            
            long long b= pq.top() ;
            pq.pop();
            
            long long sum = a +b  ;
            ans += sum ;
            pq.push(sum) ;
        }
        return ans ; 
    }

int main(){

    long long arr[4] = {4, 3, 2, 6} ;
    cout << minCost(arr ,4 ) << endl;


}