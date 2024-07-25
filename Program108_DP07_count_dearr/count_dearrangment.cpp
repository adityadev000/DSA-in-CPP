//p108 -> dp07 ->   count Derangements

#include<iostream>
#include<bits/stdc++.h>
#define MOD 1000000007

using namespace std;



long long int solve_rec(int n) {

    // base case
    // Yadi n 1 hai, to 0 return karo
    if( n == 1 ) return 0 ;
    
    // Yadi n 2 hai, to 1 return karo
    if( n == 2 ) return 1 ;

    // Recursion case: Calculate ans using recursive formula
    return (((n-1) % MOD) * ((solve_rec(n-1) % MOD ) + (solve_rec(n-2 ) % MOD ) ))  ;
}


long long int solve_rec_memo(int n , vector<long long int > & dp  ){

    if( n == 1 ) return 0 ;
    if( n == 2 ) return 1 ;
    if(dp[n] != -1) return dp[n] ;

    dp[n]  =   ( ((n-1) % MOD) * ((solve_rec_memo(n-1 ,dp ) % MOD ) + (solve_rec_memo(n-2 ,dp ) % MOD ) ) % MOD)  ;

    return dp[n] ;
}


long long int solve_tabulisation(int n  ){

    vector<long long int> dp(n+1 ,0) ;

    dp[1] = 0  ;
    dp[2] = 1  ;

    for(int  i = 3 ;i<= n ;i ++ ){

        dp[i] =  ( ((i-1) % MOD) * ((dp[i-1] % MOD ) + (dp[i-2] % MOD ) ) % MOD)  ;
    }


    return dp[n] ;
}
long long int solve_space_opt(int n  ){



    long long int prev2  = 0  ;
    long long int prev1  = 1  ;

    for(int  i = 3 ;i<= n ;i ++ ){

        long long int ans  =  ( ((i-1) % MOD) * ((prev1 % MOD ) + (prev2 % MOD ) ) % MOD)  ;
        prev2 = prev1 ;
        prev1 = ans ;

    }


    return prev1 ;
}





long long int countDerangements(int n) {
    // Write your code here.

    // return solve_rec( n ) ;


    // vector<long long int> dp(n+1 ,-1) ;
    // return solve_rec_memo(n ,dp ) ; 

    // return solve_tabulisation(n ) ;


    return solve_space_opt(n ) ;
}


int main(){


    cout << countDerangements(5) << endl;

}