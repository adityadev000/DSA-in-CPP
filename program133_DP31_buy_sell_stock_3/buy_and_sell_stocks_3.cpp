//p132 -> dp31-> buy ans sell stocks 3 -> at most 2 times.
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int solve_rec(int i , int buy ,int limit , vector<int>& prices  ){
        if( i>= prices.size() || limit <= 0 ){
            return 0 ;
        }
        int profit =0 ;
        if(buy){
            profit = max(( (0-prices[i])  +  (solve_rec(i+1 ,0 ,limit ,prices) ) ) , ( (0) + (solve_rec(i+1 , 1,limit , prices)  )));
        }
        else{
            profit = max(( (prices[i])  +  (solve_rec(i+1 ,1,limit-1 ,prices) ) ) , ( (0) + (solve_rec(i+1 , 0 ,limit, prices)  ))) ;
        }

        return profit ;
    }
    int solve_rec_memo(int i , int buy ,int limit , vector<int>& prices, vector<vector<vector<int>>>& dp  ){
        if( i>= prices.size() || limit <= 0 ){
            return 0 ;
        }
        if(dp[i][buy][limit] != -1 ) return dp[i][buy][limit] ;
        
        int profit =0 ;
        if(buy){
            profit = max(( (0-prices[i])  +  (solve_rec_memo(i+1 ,0 ,limit ,prices , dp ) ) ) , ( (0) + (solve_rec_memo(i+1 , 1,limit , prices , dp )  )));
        }
        else{
            profit = max(( (prices[i])  +  (solve_rec_memo(i+1 ,1,limit-1 ,prices , dp ) ) ) , ( (0) + (solve_rec_memo(i+1 , 0 ,limit, prices , dp )  ))) ;
        }

        return dp[i][buy][limit] =  profit ;
    }


    int solve_tabulisation( vector<int>& prices  ){

        int n =prices.size() ;
        vector<vector<vector<int>>> dp(n+1 , vector<vector<int>> (2 , vector<int> (3 ,0 ))) ;
      
        for(int i = n-1 ;i>=0 ;i -- ){

            for(int buy = 0 ; buy <=1 ; buy ++ ){

                for(int limit = 1 ; limit < 3 ; limit ++ ){

                    int profit =0 ;
                    if(buy){
                        profit = max(( (0-prices[i])  +  dp[i+1][0][limit] ) , ( (0) +  dp[i+1][1][limit]));
                    }
                    else{
                        profit = max(( (prices[i])  +   dp[i+1][1][limit -1 ] ) , ( (0) +  dp[i+1][0][limit] )) ;
                    }

                    dp[i][buy][limit] =  profit ;

                }
            }
        }
        return dp[0][1][2] ;
    }

    int solve_space_opt( vector<int>& prices  ){

        int n =prices.size() ;
        // vector<vector<vector<int>>> dp(n+1 , vector<vector<int>> (2 , vector<int> (3 ,0 ))) ;
        vector<vector<int> > curr (2 , vector<int> (3 ,0 ) ) ;
        vector<vector<int> > next  (2 , vector<int> (3 ,0 ) ) ;
      
        for(int i = n-1 ;i>=0 ;i -- ){

            for(int buy = 0 ; buy <=1 ; buy ++ ){

                for(int limit = 1 ; limit < 3 ; limit ++ ){

                    int profit =0 ;
                    if(buy){
                        profit = max(( (0-prices[i])  +  next[0][limit] ) , ( (0) +  next[1][limit]));
                    }
                    else{
                        profit = max(( (prices[i])  +   next[1][limit -1 ] ) , ( (0) +  next[0][limit] )) ;
                    }

                    curr[buy][limit] =  profit ;

                }
            }
            next = curr ;
        }
        return next[1][2] ;
    }
    int maxProfit(vector<int>& prices) {
        // return solve_rec(0 , 1 ,2,  prices );

        // int n =prices.size() ;
        // vector<vector<vector<int>>> dp(n , vector<vector<int>> (2 , vector<int> (3 ,-1 ))) ;
        // return solve_rec_memo(0 ,1, 2 , prices ,dp ) ;

        // return solve_tabulisation(prices) ;

        return solve_space_opt(prices) ;

    }


int main(){


    vector<int >prices = { 3,3,5,0,0,3,1,4} ; 

    cout << maxProfit(prices) << endl;

}