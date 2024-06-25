//p103 -> dp02 -> min Cost Climbing Stairs
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int solve_rec(vector<int>& cost , int n ){
        //base caase
        if(n == 0 ){
            return cost[0] ;
        }
        if(n == 1 ){
            return cost[1] ;
        }

        return cost[n] + min(solve_rec(cost ,n-1) , solve_rec(cost,n-2)) ;
    }

    int solve_rec_memo(vector<int>& cost , int n , vector<int> & dp){

        if(n == 0 ){
            return cost[0] ;
        }
        if(n == 1 ){
            return cost[1] ;
        }

        if(dp[n] != -1) {

            return dp[n] ; 
            
        }
        dp[n] =  cost[n] + min(solve_rec_memo(cost ,n-1 ,dp) , solve_rec_memo(cost,n-2 ,dp )) ;

        return dp[n] ;

    }

    int solve_opt(vector<int>& cost , int n ){

        

        int prev2 = cost[0] ; 
        
        int prev1 = cost[1] ;

        for(int i=2 ;i < n ;i++  ){

            int curr  =  cost[i] + min(prev2 ,prev1 ) ;

            prev2 =prev1; 
            prev1 =curr ;

        }
        

        return min(prev2 , prev1 ) ;

    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n =cost.size() ;

        // vector<int> dp(n+1 ,-1) ;
        // int ans = min(solve_rec_memo(cost ,n-1 , dp ), solve_rec_memo(cost,n-2, dp )) ;

        // return solve_tabulation(cost ,n );

        return solve_opt(cost ,n );



    }


int main(){

        vector<int> c ={10,15,20} ;

        cout << minCostClimbingStairs(c) << endl;


}