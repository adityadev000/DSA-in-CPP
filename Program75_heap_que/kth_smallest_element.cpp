//p75  -> q1 -> Kth smallest element

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int kthSmallest(int arr[], int l, int r, int k) {
        
        //by max heap
        priority_queue<int> pq ;
        
        for(int i =0 ;i< k ;i ++) {
            pq.push(arr[i]) ;
        }
        for(int i =k ; i<=r ; i++ ){
            if(arr[i] < pq.top() ){
                pq.pop() ;
                pq.push(arr[i]) ;
            }
        }
        return pq.top() ;
    }

int main(){

    int arr[5] = {4,7,3,2,9} ;
    cout << kthSmallest(arr , 0 , 4 , 3) << endl;


}