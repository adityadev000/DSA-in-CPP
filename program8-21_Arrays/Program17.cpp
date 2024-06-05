#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void bubbleSorting(vector<int>&a ,int n ){
    for(int i = 1; i< n ; i++){
        bool swapped = false;
        for(int j = 0; j < (n-i) ; j++){

            if (a[j] > a[j+1]){
                swap(a[j] , a[j+1]);
                swapped = true;
            }
        }
        if (swapped == false){
            break;
        }
    }
    for(int i = 0; i< n ; i++){
        cout << a[i] <<" " ;
    }
}

int main(){

    vector<int> arr = {1,4,7,3,9};
    bubbleSorting(arr ,5);


}