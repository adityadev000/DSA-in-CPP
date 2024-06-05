//p75  -> q3 -> Merge two binary Max heaps

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void heapify  (vector<int> &arr , int n ,int i){
    int largest = i ;
    int left  =2 *i +1  ;
    int right = left+1 ;

    if(left < n && arr[largest] < arr[left]){
        largest = left  ;
    } 
    if(right < n && arr[largest] < arr[right]){
        largest = right  ;
    } 
    if(largest != i ){
        swap(arr[largest] , arr[i] ) ;
        heapify(arr ,n ,largest) ;
    }
}

void merge (vector<int> &a, vector<int> &b , vector<int> & c ,int n, int m){
    
    for(int i =0 ;i< n ;i ++ ){
        c.push_back(a[i] ) ;
    }
    for(int i =0 ;i< m ;i ++ ){
        c.push_back(b[i] ) ;
    }
    
}
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector<int> c ;
        merge (a ,b ,c ,n, m );
        
        int s = c.size() ;
        for(int i = s/2 -1 ; i >= 0 ;i --) {
            heapify(c , s , i) ;
        }
        return c ;
    }

int main(){

    vector<int > a = {10, 5, 6, 2};
    vector<int > b = {12, 7, 9};
    vector<int > c = mergeHeaps(a,b,4,3) ;

    for(auto i : c ){
        cout << i << " ";
    }cout <<  endl;



}