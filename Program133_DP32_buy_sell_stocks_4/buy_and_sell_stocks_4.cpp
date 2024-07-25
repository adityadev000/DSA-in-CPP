//p133 -> dp32-> buy ans sell stocks 4 -> at most k times.
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int solve_rec(int i , int opr ,int limit , vector<int>& prices  ){
        if( i>= prices.size() || opr >= 2* limit  ){
            return 0 ;
        }
        int profit =0 ;
        if(opr % 2 ==0 ){
            profit = max(( (0-prices[i])  +  (solve_rec(i+1 ,opr +1  ,limit ,prices) ) ) , ( (0) + (solve_rec(i+1 , opr,limit , prices)  )));
        }
        else{
            profit = max(( (prices[i])  +  (solve_rec(i+1 ,opr +1 ,limit ,prices) ) ) , ( (0) + (solve_rec(i+1 , opr  ,limit, prices)  ))) ;
        }

        return profit ;
    }
    int solve_rec_memo(int i , int opr ,int limit , vector<int>& prices,  vector<vector<int>> & dp  ){
        if( i>= prices.size() || opr >= 2* limit  ){
            return 0 ;
        }
        if(dp[i][opr] != -1 ) return dp[i][opr] ; 
        int profit =0 ;

        if(opr % 2 ==0 ){
            profit = max(( (0-prices[i])  +  (solve_rec_memo(i+1 ,opr +1  ,limit ,prices , dp ) ) ) , ( (0) + (solve_rec_memo(i+1 , opr,limit , prices , dp )  )));
        }
        else{
            profit = max(( (prices[i])  +  (solve_rec_memo(i+1 ,opr +1 ,limit ,prices , dp ) ) ) , ( (0) + (solve_rec_memo(i+1 , opr  ,limit, prices , dp )  ))) ;
        }

        return dp[i][opr] =  profit ;
    }


    int solve_tabulisation( vector<int>& prices,int k   ){

        int n =prices.size() ;
        vector<vector<int>> dp(n+1 , vector<int> (2*k+1 ,0 )) ;
      
        for(int i = n-1 ;i>=0 ;i -- ){

            for(int opr = 0 ; opr <2*k ; opr ++ ){
                
                int profit = 0; 

                 if(opr % 2 ==0 ){
                    profit = max(( (0-prices[i])  +  dp[i+1][opr+1] ) , ( (0) +  dp[i+1][opr]));
                }
                else{
                    profit = max(( (prices[i])  +   dp[i+1][opr +1 ] ) , ( (0) +  dp[i+1][opr])) ;
                }

                dp[i][opr] =  profit ;

                
            }
        }
        return dp[0][0] ;
    }

    int solve_space_opt( vector<int>& prices ,int k  ){

        int n =prices.size() ;
        vector<int>  curr (2* k+1 ,0 )  ;
        vector<int>  next (2* k+1 ,0 )  ;
      
        for(int i = n-1 ;i>=0 ;i -- ){

            for(int opr = 0 ; opr <2*k ; opr ++ ){
                
                int profit = 0; 

                 if(opr % 2 ==0 ){
                    profit = max(( (0-prices[i])  +  next[opr+1] ) , ( (0) +  next[opr]));
                }
                else{
                    profit = max(( (prices[i])  +   next[opr +1 ] ) , ( (0) +  next[opr])) ;
                }

               curr[opr] =  profit ;

                
            }
            next = curr ;
        }
        return next[0] ;
    }
    int maxProfit(int k, vector<int>& prices) {
        // return solve_rec(0 , 0 ,k,  prices );

        // int n =prices.size() ;
        // vector<vector<int>> dp(n  , vector<int> (2* k +1  ,-1 ) );
        // return solve_rec_memo(0 ,0, k , prices ,dp ) ;

        // return solve_tabulisation(prices , k ) ;

        return solve_space_opt(prices , k ) ;

    }


int main(){

    vector<int >prices = {3,2,6,5,0,3} ; 

    cout << maxProfit( 2 ,prices )  << endl;


}