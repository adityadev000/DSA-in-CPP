//p127 -> dp26-> Numbers of unique BSTs.
#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int solve_rec(int n) {
    // Base case: agar n 1 ya 1 se chhota hai, return 1
    if (n <= 1) return 1;

    int ans = 0;

    // Har possible position j ke liye calculate karte hain
    for (int j = 1; j <= n; j++) {
        // Answer update karte hain
        ans += solve_rec(j - 1) * solve_rec(n - j);
    }

    // Final answer return karte hain
    return ans;
}


    int solve_rec_memo(int n ,vector<int> &dp){
        if( n <= 1 ) return 1 ;
        if(dp[n] != -1 ) return dp[n] ;

        int ans =0 ;

        for(int j = 1 ;j<= n ;j ++ ){
            ans += solve_rec_memo(j-1 ,dp ) * solve_rec_memo(n-j ,dp ) ;
        }

        return dp[n] = ans ;
    }

    int solve_tab(int n ){
        vector<int> dp(n+1 ,0) ;

        dp[0] = dp[1] = 1 ;

        for(int i= 2 ;i<=n ;i ++ ){

            int ans =0 ;

            for(int j = 1 ;j<= i ;j ++ ){
                ans += dp[j-1] * dp[i-j] ;
            }

            dp[i] = ans ;

        }

        return dp[n] ;
    }


     double ncr(int n, int r){
        double ans = 1;
        for(int i = 1; i <= r; i++)
            ans = ans * (n - r + i) / i;
        return ans;
    }
    int solve_cat(int n) {
        double n_c_n = ncr(2*n, n);
        return int((n_c_n / double(n + 1)));
    }
    int numTrees(int n) {
        
        // return solve_rec(n) ;

        // vector<int> dp(n+1 ,-1) ;
        // return solve_rec_memo(n ,dp) ;

        return solve_tab(n) ;

        // return solve_cat(n) ;

    }

int main(){

    cout << "ans = " << endl;
    cout << numTrees(5) << endl;

}