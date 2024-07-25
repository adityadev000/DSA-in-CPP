//p134 -> dp33-> buy ans sell stocks 5 -> multiple times but after paying trans. fee .
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int solve_rec(int i , int buy ,vector<int>& prices  ,int fee ){
        if( i>= prices.size() ){
            return 0 ;
        }
        int profit =0 ;
        if(buy){
            profit = max(( (0-prices[i])  +  (solve_rec(i+1 ,0 ,prices , fee ) ) ) , ( (0) + (solve_rec(i+1 , 1 , prices , fee )  )));
        }
        else{
            profit = max(( (prices[i] - fee )  +  (solve_rec(i+1 ,1 ,prices , fee ) ) ) , ( (0) + (solve_rec(i+1 , 0 , prices , fee )  ))) ;
        }

        return profit ;
}

    int solve_rec_memo(int i , int buy ,vector<int>& prices , vector<vector<int>> & dp ,int fee ){
        if( i>= prices.size() ){
            return 0 ;
        }
        if(dp[i][buy] != -1 ) return dp[i][buy] ;

        int profit =0 ;
        if(buy){
            profit = max(( (0-prices[i])  +  (solve_rec_memo(i+1 ,0 ,prices ,dp ,fee) ) ) , ( (0) + (solve_rec_memo(i+1 , 1 , prices ,dp ,fee)  )));
        }
        else{
            profit = max(( (prices[i] - fee )  +  (solve_rec_memo(i+1 ,1 ,prices ,dp,fee) ) ) , ( (0) + (solve_rec_memo(i+1 , 0 , prices ,dp ,fee)  ))) ;
        }

        return dp[i][buy] = profit ;
    }
    int solve_tabulisation(vector<int>& prices ,int fee  ){
        int n = prices.size() ;

        vector<vector<int>> dp(n+1 , vector<int>(2 ,0 )) ;

        for(int i =n-1 ;i>= 0 ;i -- ){
            for(int buy =0 ; buy <= 1 ;buy ++ ){

                int profit =0 ;
                if(buy){
                    profit = max ( (0-prices[i])  +  dp[i+1][0]  , ( (0) + dp[i+1][1] ));
                }
                else{
                    profit = max(( (prices[i]- fee )  +  dp[i+1][1] ) , ( (0) + dp[i+1][0]  )) ;
                }


            dp[i][buy] = profit ;
            }
        }
        return dp[0][1] ; 
    }
    int solve_space_opt(vector<int>& prices ,int fee   ){
        int n = prices.size() ;

        // vector<vector<int>> dp(n+1 , vector<int>(2 ,0 )) ;
        vector<int> curr(2,0) ;
        vector<int> next(2,0) ;

        for(int i =n-1 ;i>= 0 ;i -- ){
            for(int buy =0 ; buy <= 1 ;buy ++ ){

                int profit =0 ;
                if(buy){
                    profit = max ( (0-prices[i])  +  next[0]  , ( (0) + next[1] ));
                }
                else{
                    profit = max(( (prices[i] -fee )  +  next[1] ) , ( (0) + next[0]  )) ;
                }


                curr[buy] = profit ;
            }
            next = curr ;
        }
        return next[1] ; 
    }

     int maxProfit(vector<int>& prices, int fee) {
        //  return solve_rec(0 , 1 , prices ,fee ) ;

        // vector<vector<int>> dp(prices.size() , vector<int>(2 ,-1 )) ;
        // return solve_rec_memo(0 , 1 , prices ,dp ,fee ) ;

        // return solve_tabulisation(prices ,fee ) ; 

        return solve_space_opt(prices , fee ) ;

    }


int main(){

    vector<int> prices = {1,3,2,8,4,9} ;

    cout << maxProfit(prices ,2 ) << endl;



}