//p128 -> dp27-> guess no. lower or higher.
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
int maxi(int a ,int b ,vector<int> & arr){
    int ans = arr[a] ;
    for(int i = a ;i<= b ;i ++ ){
        ans = max(ans , arr[i]) ;
    }
     return ans ;
}

int solve_rec(int s, int e, vector<int>& arr) {
    // Base case: agar start index end se bada ya equal hai, return 0
    if (s >= e) {
        return 0;
    }
    
    // Minimum answer ko initialize kar rahe hain
    int ans = INT_MAX;

    // Har possible position k ke liye check karte hain
    for (int k = s; k < e; k++) {
        // Minimum value update karte hain
        ans = min(ans, maxi(s, k, arr) * maxi(k + 1, e, arr) + solve_rec(s, k, arr) + solve_rec(k + 1, e, arr));
    }

    // Minimum answer return karte hain
    return ans;
}


int solve_rec_memo(int s  , int e ,vector<vector<int>>& dp){
    if( s >= e  )  return 0 ;
    if(dp[s][e] != -1 ) return dp[s][e] ; 
    int ans = INT_MAX ;

    for(int i =  s ; i<= e ;i++ ){

        ans = min(ans , i+ max(solve_rec_memo(s , i-1,dp), solve_rec_memo(i+1 , e,dp ) ) ) ;
    }
    return dp[s][e] =  ans ;
}
int solve_tabulisation(int n ){
    vector<vector<int>> dp(n+2 , vector<int> (n+2 , 0 )) ;
    
    for(int s = n ; s >= 1 ; s-- ){

        for(int e = s ; e <= n  ;e ++  ){

            if(s == e ) continue ;
            else{

                int ans = INT_MAX ;
                for(int i =  s ; i<= e ;i++ ){

                    ans = min(ans , i+ max(dp[s][i-1], dp[i+1][e] ) ) ;
                }
                dp[s][e] =  ans ;
            }

        }
    }
    return dp[1][n] ;
}

int getMoneyAmount(int n) {
    
    // return solve_rec(1 ,n ) ;

    // vector<vector<int>> dp(n+1 , vector<int> (n+1 ,-1 )) ;
    // return solve_rec_memo(1 ,n ,dp );

    return solve_tabulisation(n) ;
}


int main(){


    cout << getMoneyAmount(12) << endl;
    cout << getMoneyAmount(16) << endl;

}