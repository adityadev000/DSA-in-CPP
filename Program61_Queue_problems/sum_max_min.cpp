//p61 -> q8 -> Sum of minimum and maximum elements of all subarrays of size k.

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int solve(int *arr, int n, int k) {
    deque<int> maxi(k) ;
    deque<int> mini(k) ;

    //process first window.
    for(int i = 0; i< k ; i++){
        
        while (!maxi.empty() && arr[i] > arr[maxi.front()]){
            maxi.pop_back() ;
        }

        while(!mini.empty() && arr[i] < arr[mini.front()]){
            mini.pop_back() ;
        }
        
        maxi.push_back(i) ;
        mini.push_back(i) ;
    }

    int ans = 0 ;
    ans += arr[maxi.front()] + arr[mini.front()] ;

    for(int i= k ; i < n ; i++ ) {
        //removal 
        if(i - maxi.front()  >= k ){
            maxi.pop_front() ;
        }
        if(i - mini.front()  >= k ){
            mini.pop_front() ;
        }

        //addition
        while (!maxi.empty() && arr[i] > arr[maxi.front()]){
            maxi.pop_back() ;
        }

        while(!mini.empty() && arr[i] < arr[mini.front()]){
            mini.pop_back() ;
        }
        
        maxi.push_back(i) ;
        mini.push_back(i) ;


        ans += arr[maxi.front()] + arr[mini.front()] ;
    }
    return ans  ;
}

int main(){

    int arr[7] = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    cout << solve(arr, 7, k) << endl;



}