#include<iostream>
using namespace std;

int binarySearch (int a[] , int n , int key){
    int start =0 , end = (n-1);
    int mid = start + (end - start) /2 ;
    while (start <=   end ){
        if (key == a[mid]){
            return mid ;
        }
        if (key > a[mid]){
            start = (mid +1);
        }
        else {
            end = (mid -1);
        }
    mid = start + (end - start) /2 ;
    }
    return -1 ;
}

int main(){

    int even [6] = {2,5,8,12,23,37};
    int odd [5] = {3,4,6,9,11};


    int evenIndex = binarySearch(even , 6 , 12);
    cout << "Element found at index at "<< evenIndex << endl;

    int oddIndex = binarySearch(odd , 5 , 11);
    cout << "Element found at index at "<< oddIndex << endl;

}