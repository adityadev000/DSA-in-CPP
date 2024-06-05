//Quicksort
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int partition (vector<int>& arr , int s ,int e) {
    int pivot  = arr[s] ;
    int cnt = 0 ;

    for(int i =s+1 ; i <= e ; i ++) {
        if (arr[i] <= pivot){
            cnt ++ ;
        }
    }
    int pivoti = s + cnt ;
    swap(arr[s] , arr[pivoti]) ;
    int i = s , j= e ;
    while (i <pivoti && j> pivoti ){
        while(arr[i] <= pivot  ){
            i++ ;
        }
        while (arr[j] >pivot){
            j-- ;
        }
        if (i <pivoti && j> pivoti) {
            swap(arr[i++] ,arr[j--]) ;
        }
    }
    return pivoti ;

}

void solve (vector<int>& arr , int s ,int e ){
    //base case 
    if (s >= e){
        return ; 
    }
    int p = partition ( arr ,  s , e) ;
    //left part call 
    solve(arr , s ,p -1) ;

    //right part call ;
    solve(arr, p+1 , e) ;

}

vector<int> quickSort(vector<int> arr)
{
    solve(arr, 0 , arr.size() -1 );
    return arr ;
}

int main(){

    vector<int> arr = {5,7,3,5,9,0,2} ;
    vector<int> ans = quickSort(arr) ;
    int n= 7 ;
    for(int i = 0; i< n ; i++){
        cout << ans[i] << " " ;
    }


}