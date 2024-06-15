// p78 -> q ->  Maximum Frequency Number
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int maximumFrequency(vector<int> &arr, int n)
{

    int maxfreq  =0 ;
    unordered_map<int ,int > m ;
    for(int i =0 ;i < n ; i ++ ){
        m[arr[i]] ++ ;
        maxfreq = max (m[arr[i]] , maxfreq) ;
    }
    int maxans = 0;
    for(int i =0 ;i < n ;i ++  ){
        if(maxfreq == m[arr[i]]) {
            maxans = arr[i] ;
            break ;
        }
    }
    return maxans ;
}

int main(){

    vector<int> arr = { 2, 2, 3, 1, 2} ;
    cout << maximumFrequency(arr, 5 ) << endl;

}