#include<iostream>
#include<bits/stdc++.h>

using namespace std;
//P33a 
bool is_sorted(int *arr ,int  n){
    if (n == 0 || n== 1)
    return 1 ;

    if(arr[0] > arr[1]){
        return false ;
    }
    else{
        return is_sorted(arr+1 , n-1) ;
    }
}



//P33b
bool linearSearch(int arr[], int size, int k ) {
    //base case
    if(size == 0) 
        return false;

    if(arr[0] == k) {
        return true;
    }
    else {
        return linearSearch(arr+1, size-1, k ) ;
    }
}

//P33c

bool binarySearch(int *arr, int s, int e , int k ) {

    //base case

    //element not found
    if(s>e)
        return false;

    int mid = s + (e-s)/2;

    //element found
    if(arr[mid] == k)
        return true;

    if(arr[mid] < k) {
        return binarySearch(arr, mid+1, e, k);
    }
    else{
        return binarySearch(arr, s, mid-1, k);
    }
}


int main(){
// p33a
    int arr1[5] = {2,4,9 , 11,17};
    int size1 = 5;

    bool ans1 = is_sorted(arr1, size1);

    if(ans1){
        cout << "Array is sorted " << endl;
    }
    else {
        cout << "Array is not sorted " << endl;
    }

//p33b
    int key = 9 ;
    bool ans2 = linearSearch(arr1, size1, key);

    if(ans2 ){
        cout << "Present " << endl;
    }
    else{
        cout << "absent " << endl;
    }

//p33c
    int arr2[11] = {2,4,6,10,14,18,22,38,49,55,222};
    int size2 = 11;
    int key2 = 222;

    cout << "Present or not " << binarySearch(arr2, 0, size2-1, key2) << endl;



}