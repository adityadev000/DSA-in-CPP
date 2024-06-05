#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//P15a -> book allocation problem
bool isPossibleallocation ( int a[] ,int n ,int  m ,int mid){
    int pagesum = 0;
    int studentcount =1;
    for(int i = 0; i< n ; i++){
        if (pagesum + a[i] <= mid ){
            pagesum += a[i];
        }
        else {
            studentcount ++;
            if (studentcount > m || a[i] > mid ) {
                return false;
            }
            pagesum = a[i];
        }
    }
    return true ;
}

int allocation (int a[] , int n ,int m ){
    int sum =0 ,ans = -1;
    int s= 0;

    for(int i = 0; i< n ; i++){
        sum += a[i];
    } 

    int e = sum;
    int mid = s +(e-s) /2;

    while (s <= e){
        if (isPossibleallocation(a ,n , m ,mid)){
            ans = mid ;
            e =(mid -1);
        }
        else {
            s =(mid +1);
        }
        mid = s +(e-s) /2;
    }
    return ans ;

}

//P15b -> agressive cows
bool isposibleaggressiveCows(vector<int> &stalls, int k,int mid ,int n){

    int cowCount = 1;
    int lastPos = stalls[0];
    for(int i = 0; i< n ; i++){
        if (stalls [i] -lastPos >= mid){
            cowCount ++ ;
            if (cowCount == k){
                return true ;
            }
            lastPos = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin() ,stalls.end());

    int s = 0;
    int n = stalls.size();
    int e=stalls[n-1];
    int ans = -1;
    int mid = s + (e-s)/2;

    while (s <=e) {
        if (isposibleaggressiveCows(stalls ,k ,mid ,n )){
            ans = mid ;
            s= (mid +1);
        }
        else {
            e = (mid -1);
        }
        mid = s + (e-s)/2;
    }
    return ans ;
}


int main(){

    int arr[4] = {10,20,30,40};
    cout << allocation (arr , 4 ,2) << endl; 

    vector <int> arr1  = {4,2,1,3,6};
    cout << aggressiveCows(arr1 ,2) << endl;


}


/*
HW PROBLEM

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int isposs(vector <int>a ,int n , int key,int mid ){
    int sum =0;
    for(int i = 0; i < n ; i++){
        int diff = a[i] - mid;
        if ((diff <= key) && (diff > 0) ){
            sum += diff;
        }
    }
    return sum ;

}

int woodCutter (vector <int>a ,int n , int key  ){
    sort(a.begin() , a.end());
    int s = 0,maxi = a[0];
    for(int i = 0; i< n ; i++){
        maxi= max (a[0], a[i]);
    }
    int e = maxi ;
    int mid = s + (e-s) /2;
    int sum = 0, ans = -1;

    while (s < e) {

        if (isposs(a ,n ,key ,mid) == key){
            ans = mid ;
            break ;

        }
        else if (isposs (a ,n ,key ,mid) > key){
            s = (mid +1);
        }
        else {
            e = (mid -1);
        }
        mid = s + (e-s) /2;
    }
    return ans ;
}

int main(){

    vector<int > arr = {20 ,15 ,10,17};
    cout << woodCutter(arr ,4 , 7) << endl;


}
*/