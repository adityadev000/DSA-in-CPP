//p109 -> dp08 ->   Ninja And The Fence

#include<iostream>
#include<bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int add (int a ,int b ){
    return ((a % MOD) + (b%MOD )) % MOD ;
}
int mul (int a ,int b ){
    return ((a % MOD)* 1LL *  (b%MOD )) % MOD ;
}

int solve_rec(int n, int k) {

    // base case
    // Yadi n 1 hai, to k return karo
    if(n == 1) return k ;
    
    // Yadi n 2 hai, to k * (k - 1) + k return karo
    if(n == 2) return add(k , mul(k ,k-1) ) ;

    // Recursion case: Calculate ans using recursive formula
    int ans = add(mul(solve_rec(n-2 , k) ,k-1) , mul(solve_rec(n-1 ,k ) ,k-1)) ;

    return ans ; 
}


int solve_rec_memo(int n , int k ,vector<int> & dp ) {

    // base case
    if(n == 1) return k ;
    if(n == 2) return add(k , mul(k ,k-1) ) ;
    if(dp[n] != -1) return dp[n] ;

    dp[n] = add(mul(solve_rec_memo(n-2 , k ,dp ) ,k-1) , mul(solve_rec_memo(n-1 ,k ,dp ) ,k-1)) ;

    return dp[n] ; 
    
}

int solve_tabulisation(int n , int k  ) {

    vector<int> dp(n+1 , 0 ) ;

    dp[1] = k ;
    dp[2] = add(k , mul(k ,k-1) ) ;

    for(int i =3 ;i<= n ;i ++ ){

        dp[i] = add(mul(dp[i -2] ,k-1) , mul(dp[i-1] ,k-1)) ;

    }

    return dp[n] ; 
    
}

int solve_opt(int n , int k  ) {

    

    int prev2 =k ;
    int prev1 = add(k , mul(k ,k-1) ) ;

    for(int i =3 ;i<= n ;i ++ ){

        int ans   = add(mul(prev2 ,k-1) , mul(prev1 ,k-1)) ;
        prev2 =prev1 ;
        prev1 =ans ;

    }

    return prev1 ;
    
}
int numberOfWays(int n, int k) {

    // return solve_rec(n ,k ) ;

    // vector<int>dp(n+1 ,-1) ;
    // return solve_rec_memo(n ,k ,dp ) ;

    // return solve_tabulisation(n ,k ) ;


    return solve_opt(n ,k );

}



int main(){

    cout << numberOfWays(4,2) << endl;


}