//p61 -> q2-> First negative integer in every window of size k

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
     vector <long long >  ans ;
     deque<long long int > q ;
     
     for(int i = 0; i< K ;i ++ ){
         if(A[i] < 0 ){
             q.push_back(i) ;
         }
     }
    if(q.size() > 0 ) ans.push_back(A[q.front()]) ;
    else  ans.push_back(0) ;
     
     for(int i = K ; i< N ;i ++ ){
         if(!q.empty() &&  ( (i-q.front() )>= K ) ){
             q.pop_front() ;
         }
         if(A[i] < 0 ){
             q.push_back(i) ;
         }
         if(q.size() > 0 ) ans.push_back(A[q.front()]) ;
         else  ans.push_back(0) ;
     
     }
     return ans  ;
 }

int main() {
        long long int arr[5] =  {-8, 2, 3, -6, 10};
        long long int k = 2;

        vector<long long> ans = printFirstNegativeInteger(arr, 5, 2);
        for (auto it : ans) cout << it << " ";
        cout << endl;
}