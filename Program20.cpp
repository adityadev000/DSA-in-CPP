#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//P20a -> reverse array after given index ;
void reverseArray(vector<int> &arr , int m){

    int i = (m+1) ;
    int j= (arr.size()-1);
    while (i < j){
        swap(arr[i], arr[j]);
        i++ ;
        j-- ;
    }      	
}

//P20b -> merge two sorted in one array;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0 , j=0;

        while (i !=m && j!= n){
            
            if(nums1[i] > nums2[j]) {
                swap (nums1[i] , nums2[j]) ;
                sort(nums2.begin() , nums2.end());
                i++ ;
            }
            else {
                i++ ;
            }
        }
        while (j != n){
            nums1[i]= nums2[j];
            i++ ;
            j++ ;
        }
    }


//P20c -> move zeros to right
void moveZeroes(vector<int>& nums) {
        int i = 0 ;
        int j = 1; 
        int x = nums.size();
        while (j != x ){
            if(nums[i] == 0 && nums[j] != 0){
                swap(nums[i] , nums[j]);
                i++ ;
                j++ ;
            }
            else if(nums[i] == 0 && nums[j] == 0){
                j ++ ;
            }
            else {
                i++ ;
                j++ ;
            }
        }
    }

int main(){

    vector<int> v1 = {4,6,3,8,6,3,5}; //7
    vector<int> v2 = {4,5,7,0,0,0}; //6
    vector<int> v3 = {2,4,8}; //3
    vector<int> v4 = {2,0,0,6,4,0};//6


    reverseArray(v1,3);
    for(int i = 0; i< 7 ; i++){
        cout << v1[i] <<"  " ;
    }
    cout  << endl << endl ;

    merge (v2,3,v3 ,3);
    for(int i = 0; i< 6 ; i++){
        cout << v2[i] <<"  " ;
    }
    cout  << endl << endl ;

    moveZeroes(v4);
    for(int i = 0; i< 6 ; i++){
        cout << v4[i] <<"  " ;
    }
    cout  << endl << endl ;
}