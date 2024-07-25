//p129 -> dp28-> MInimum cost tree form leaf values.
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


int solve_rec(int s ,int e , vector<int> & arr){
    if(s >= e ){
        return 0; 
    }
    int ans = INT_MAX ;
    for(int k = s ; k<e ; k ++ ){
        ans =min(ans , maxi(s ,k,arr)*maxi(k+1,e ,arr) + solve_rec(s,k , arr) + solve_rec(k+1 ,e , arr)  ) ;
    }
    return ans ;
}

int solve_rec_memo(int s ,int e , vector<int> & arr , vector<vector<int>>& dp){
    if(s >= e ){
        return 0; 
    }
    if(dp[s][e] != -1 ) return dp[s][e] ; 
    int ans = INT_MAX ;
    for(int k = s ; k<e ; k ++ ){
        ans =min(ans , maxi(s ,k,arr)*maxi(k+1,e ,arr) + solve_rec_memo(s,k , arr ,dp) + solve_rec_memo(k+1 ,e , arr ,dp)  ) ;
    }
    return dp[s][e] =  ans ;
}

int solve_tabulisation( vector<int> & arr ,int n ){

        vector<vector<int>> dp(n+1 , vector<int>(n+1 , 0 )) ; 
        for(int s = n -1 ;s >= 0 ; s -- ){

            for(int e = s ; e < n ;e ++ ){
                
                if(s == e ) continue ;
                int ans = INT_MAX ;
                for(int k = s ; k< e ; k ++ ){
                    ans =min(ans , maxi(s ,k,arr)*maxi(k+1,e ,arr) + dp[s][k] + dp[k+1][e]  ) ;
                }
                dp[s][e] =  ans ;

            }
        }

        return dp[0][n-1] ; 
    }

int mctFromLeafValues(vector<int>& arr) {
    int n = arr.size() ;
    // return solve_rec(0 ,n- 1 , arr );

    // vector<vector<int>> dp(n+1 , vector<int>(n+1 , -1 )) ;
    // return solve_rec_memo(0 ,n- 1 , arr,dp );

    return solve_tabulisation(arr , n ) ;
}


int main(){

    vector<int> arr = {6,2,4} ;

    cout << mctFromLeafValues(arr) << endl;


}