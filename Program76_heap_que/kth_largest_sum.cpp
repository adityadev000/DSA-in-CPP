//p76 -> q1 ->  K-th Largest Sum Subarray.
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int getKthLargest(vector<int> &arr, int k)
{
	//	Write your code here.
	priority_queue<int , vector<int> , greater<int> > mh ;

	int n = arr.size() ;
	for(int i =0 ;i< n ;i ++ ) {
		int sum =0 ; 
		for(int j =i ;j < n ;j ++ ){
			sum += arr[j] ;
			if(mh.size() < k ){
				mh.push(sum) ;
			}else {
				if(sum > mh.top()){
					mh.pop() ;
					mh.push(sum) ;
				}
			}
		}
	}
	return mh.top() ;
}

int main(){

    vector<int> a = {3,5,7,2,9,1} ;

    cout << getKthLargest(a , 3) << endl;


}