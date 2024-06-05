#include<iostream>
using namespace std;

//p13a;
int firstOccurance(int a[] , int n,int key){
    int s = 0 ,e = (n-1) ,ans =0;
    int mid = (s + (e-s)/2);
    while (s<=e){
        if (a[mid] == key ){
            ans = mid;
            e = (mid -1);
        }
        else if (a[mid] > key ){
            e = mid -1 ;
        }
        else {
            s = mid +1;
        }
        mid = (s + (e-s)/2);
    }
    return ans;
}


int lastOccurance(int a[] , int n,int key){
    int s = 0 ,e = (n-1) ,ans =0;
    int mid = (s + (e-s)/2);
    while (s<=e){
        if (a[mid] == key ){
            ans = mid;
            s = (mid +1);
        }
        else if (a[mid] > key ){
            e = mid -1 ;
        }
        else {
            s = mid +1;
        }
        mid = (s + (e-s)/2);
    }
    return ans;
}
//p13b ;
int findPeakElementInMountainArray (int a[] , int n){
    int s =0 ,e = (n-1);
    int mid = s + (e-s)/2 ;

    while (s <e){
        if (a[mid] < a[mid +1]){
            s = (mid +1) ;
        }
        else {
            e = mid;
        }
        mid = s + (e-s)/2 ;
    }
    return a[s] ;
}

int main(){

    int arr [7] = {1,2,3,3,3,3,5};
    int arr1 [4] = {3,4,5,1};

    cout << "first occr of 3 is at index "
         << firstOccurance(arr , 7 ,3) << endl;

    cout << "last occr of 3 is at index " 
         <<lastOccurance(arr , 7 ,3) << endl;

    cout << "peak element int the array is "
        << findPeakElementInMountainArray(arr1 ,4) << endl;

}