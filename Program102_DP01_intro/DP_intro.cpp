
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

//p101a fib fnc top - down mtd.
int fib_A(int n ,vector<int>& dp ){

        if(n == 1 || n== 0 ){
                return n ;
        }

        if(dp[n] != -1 ){

                return dp[ n]  ;

        }

        dp[n] = fib_A(n-1 ,dp) + fib_A(n-2 ,dp) ;

        return dp[n] ; 
}

//p101b fib fnc bottom - up mtd.
int fib_B(int n ,vector<int>& dp ){

        dp[1] = 1 ;
        dp[0] = 0 ;

        for(int i =2 ;i<= n ;i ++ ){

                dp[i] = dp[i-2] + dp[i-1] ;

        }


        return dp[n] ; 
}

//p101c fib fnc bottom - up mtd space optimised.
int fib_B_op(int n ){

        int prev1 = 1 ;
        int prev2 = 0 ;

        for(int i =2 ;i<= n ;i ++ ){

                int curr = prev1 + prev2 ;
                prev2 = prev1 ;
                prev1 = curr ;

        }

        return prev1 ;

}

int main(){

 int n ;
        cin >>n ;


        // vector<int> dp(n+1 ,-1 ) ;
        // cout << fib_A(n,dp) << endl;

        // cout << fib_B(n,dp) << endl;

        cout << fib_B_op(n )<<endl  ;



}