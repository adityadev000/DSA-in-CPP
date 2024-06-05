#include<iostream>
#include<vector>
using namespace std;


void insertionSort(vector <int> &arr){
    int n = arr.size();
    for(int i = 1; i< n ; i++){

        int temp = arr[i];
        int j = (i-1) ;

         while (j>=0){
            if (arr[j] > temp){
                //shift
                arr[j+1] = arr[j];
            }
            else {
                //already sorted
                break ;
            }
            j-- ;
        }
        arr[j+1] = temp;
    }

    for(int i = 0; i< n ; i++){
        cout << arr[i] << " ";
    }

}

int main(){

    vector <int> arr = {1,8,5,3,0};
    insertionSort(arr);
}