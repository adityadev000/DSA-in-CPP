//p123 -> dp22-> Partition Equal Subset Sum

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int solve_rec(int i, int N, int arr[], int target) {
    // Base case: agar target 0 ho jaye, to return 1 (solution mil gaya)
    if (target == 0) return 1;

    // Agar index array ke size se bada ho jaye ya target negative ho jaye, to return 0 (solution nahi mila)
    if (i >= N || target < 0) return 0;

    // Current element ko include karke solve karo (target me se current element ko subtract karke)
    int incl = solve_rec(i + 1, N, arr, target - arr[i]);

    // Current element ko exclude karke solve karo (target ko same rakhte hue)
    int excl = solve_rec(i + 1, N, arr, target);

    // Include ya exclude karne se agar koi bhi solution milta hai to return 1, nahi to return 0
    return incl || excl;
}

    
    int solve_rec_memo(int i , int N , int arr[] ,int target,vector<vector<int>>& dp  ){
        
        //bc
        if(target == 0 ) return 1 ;
        
        if(i >= N || target < 0) return 0 ;
        
        if(dp[i][target] != -1 ) return dp[i][target] ; 
        
        int incl = solve_rec_memo(i+1 , N ,arr , target - arr[i] , dp) ;
        
        int excl = solve_rec_memo(i+1 , N, arr , target ,dp  ) ;
        
        return dp[i][target] = (incl or excl) ;
        
    }
    
    int solve_tabulisation( int N , int arr[] ,int target ){
        
        vector<vector<int>> dp(N+1 , vector<int> (target +1 , 0 )) ; 
        
        for(int i =0 ; i<= N ;i ++ ){
            
            dp[i][0] = 1 ;
        }
        
        
       for(int i = N-1 ;i>= 0 ; i -- ){
           
           for(int t = 0 ; t <= target ; t ++ ){
               
               int incl = 0; 
               
               if(t-arr[i] >=0 )
                incl = dp[i+1][t-arr[i]] ;
                
                int excl = dp[i+1][t] ;
                
                dp[i][t] = (incl or excl) ;
               
           }
       }
        
        return dp[0][target] ;
        
    }
    
    int solve_space_opt( int N , int arr[] ,int target ){
        
        // vector<vector<int>> dp(N+1 , vector<int> (target +1 , 0 )) ; 
        
        vector<int> curr(target+1 , 0 ) ;
        vector<int> next(target+1 , 0 ) ;
        
        // for(int i =0 ; i<= N ;i ++ ){
            
            next[0] = 1 ;
        // }
        
        
       for(int i = N-1 ;i>= 0 ; i -- ){
           
           for(int t = 0 ; t <= target ; t ++ ){
               
               int incl = 0; 
               
               if(t-arr[i] >=0 )
                incl = next[t-arr[i]] ;
                
                int excl = next[t] ;
                
               curr[t] = (incl or excl) ;
             
           }
           
           next = curr ;
           
       }
        
        return next[target] ;
        
    }
    int equalPartition(int N, int arr[])
    {
        int sum = 0 ;
        for(int i =0; i< N ;i ++ ){
            
            sum += arr[i] ; 
            
        }
        
        if(sum %2 == 1 ) return 0 ;
        
        else{
            
            // return solve_rec(0, N , arr , sum /2  ) ;
            
            // vector<vector<int>> dp(N , vector<int> ((sum/2) +1 , -1 )) ;
            // return solve_rec_memo(0, N , arr , sum /2 , dp) ;
            
            // return solve_tabulisation( N , arr , sum /2 ) ;
            
            return solve_space_opt( N , arr , sum /2 ) ;
            
        }
    }


int main(){

    int n =  4 ;
    int arr[n] = {1, 5, 11, 5} ;

    cout << equalPartition(n , arr)  << endl;


}