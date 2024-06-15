//p77 -> q2 -> Median in a stream
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int signum(int a ,int b ){
	if(a>b) return 1 ;
	else if(a < b ) return -1 ;
	else return 0 ; 
}


void get_median(int element  ,priority_queue<int>&  maxi,
				priority_queue<int , vector<int> ,greater<int>>& mini,
				int &median )
				{
					switch(signum(maxi.size() ,mini.size())) {

						case 0 : if(element > median){ // iske baad -1 .
									mini.push(element) ;
									median = mini.top() ;
								}
								else { 					//iske baad 1.
									maxi.push(element) ;
									median = maxi.top() ;
								}
								break ;
						
						case 1 : if(element > median){
									mini.push(element) ;
									median = (mini.top()+maxi.top())/2  ;
								}
								else {
									mini.push(maxi.top());
									maxi.pop() ;
									maxi.push(element) ;
									median =  (mini.top()+maxi.top())/2 ;
								}
								break ;
						
						case -1 : if(element > median){
									maxi.push(mini.top());
									mini.pop() ;
									mini.push(element) ;
									median =  (mini.top()+maxi.top())/2 ;
								}
								else {
									maxi.push(element) ;
									median = (mini.top()+maxi.top())/2  ;
								}
								break; 
					}
				}

vector<int> findMedian(vector<int> &arr, int n){
	// Write your code here 
	vector<int> result ;
	priority_queue<int> maxi ;
	priority_queue<int , vector<int> ,greater<int>> mini ;
	int median = -1 ;

	for(int i =0 ; i < n ;i ++ ){
		get_median (arr[i] , maxi , mini , median) ;
		result.push_back(median) ;
	}
	return result ;
}


int main(){

    vector<int> a = {5,8,3,9,1} ;
    vector<int> ans = findMedian(a , 5) ;

    for(auto i : ans){
        cout << i  << " " ;
    }cout  << endl;


}