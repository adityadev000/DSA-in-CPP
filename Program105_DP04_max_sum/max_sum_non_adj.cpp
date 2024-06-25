//p105 -> dp04 ->  Maximum Sum of Non-Adjacent Elements. 

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int solve_rec(vector<int> &nums , int i ){

    // base case agar hum end pe pahunch gaye to return 0
    if(i >= nums.size() ){
        return 0 ;
    }
    // agar nums size zero ho to pehla element return kar do
    if(nums.size() == 0 ) return nums[0] ;

    // include current element aur agle se agle element pe chale jao
    int incl = solve_rec(nums , i+2) + nums[i] ;
    // exclude current element aur agle element pe chale jao
    int excl = solve_rec(nums ,i+1 ) +0 ;

    // max of include aur exclude return karo
    return max(incl , excl ) ;
}

int solve_rec_memo(vector<int> &nums , int i,vector <int>& dp ){

    // base case agar hum end pe pahunch gaye to return 0
    if(i >= nums.size() ){
        return 0 ;
    }
    // agar nums size zero ho to pehla element return kar do
    if(nums.size() == 0 ) return nums[0] ;

    // memoization check kar lo pehle
    if(dp[i] != -1 ){
        return dp[i] ; 
    }

    // include current element aur agle se agle element pe chale jao
    int incl = solve_rec_memo(nums , i+2,dp ) + nums[i] ;
    // exclude current element aur agle element pe chale jao
    int excl = solve_rec_memo(nums ,i+1 ,dp ) +0 ;

    // max of include aur exclude store karo dp mein
    dp[i] =  max(incl , excl ) ;

    // dp value return karo
    return dp[i] ; 
}

int solve_tabulation (vector<int> &nums ){

    int n = nums.size() ;
    // dp array initialize karo -1 se
    vector<int> dp(n ,-1) ;

    // pehla element dp mein daal do
    dp[0] = nums[0] ;
    dp[1] = nums[1] ; 

    // baki elements ke liye loop
    for(int i =2 ;i< n ;i++ ){
        // include aur exclude ke values nikal lo
        int incl = dp[i-2] + nums[i] ;
        int excl = dp[i-1] + 0 ;

        // dp mein max value store karo
        dp[i] = max(incl ,excl ); 
    }

    // last element return karo
    return dp[n-1] ;
}

int solve_opt(vector<int>& nums ,int n  ){

    // pehle do elements ke liye initialize karo
    int prev2 = 0 ;
    int prev1 = nums[0] ;

    // baki elements ke liye loop
    for(int i =1 ;i < n; i++ ){

        // include aur exclude ke values nikal lo
        int incl = prev2 + nums[i] ;
        int excl = prev1 +0 ;
        
        // max value nikal lo
        int ans = max(incl , excl );
        // prev values update karo
        prev2  = prev1 ;
        prev1 = ans ;
    }

    // final answer return karo
    return prev1 ;
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.

    int n = nums.size() ;
    // return solve_rec(nums , 0) ;

    // vector <int> dp(n ,-1) ;
    // return solve_rec_memo(nums , 0 ,dp ) ;

    return solve_tabulation(nums) ;

    // return solve_opt(nums ,n );
}



int main(){

    vector<int> nums ={9,9,8,2} ;

    cout <<"Max sum = " <<maximumNonAdjacentSum(nums) << endl;


}