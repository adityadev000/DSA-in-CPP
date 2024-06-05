#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void selectionSort(vector<int>& arr, int n)
{   
    for(int i =0 ;i <(n-1) ; i ++){
        int minindex = i;

        for (int j = i+1; j <n ;j ++) {
            if (arr[j] < arr[minindex]){
            minindex =j;

            }
        } 
        swap (arr [minindex] , arr[i]);
    }

    for(int i = 0; i< n ; i++){
        cout << arr[i]  << "  ";
    }
}

int main(){

    vector <int>arr = {6,3,1,8,9,4};
    selectionSort(arr ,6);


}