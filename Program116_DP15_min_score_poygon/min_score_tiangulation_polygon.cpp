//p116 -> dp15->  min Score Triangulation of polynomial.
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int solve_rec(vector<int>& v, int i, int j) {
    // Base case
    // Agar i+1 j se ek kam hai, to 0 return karo (koi element nahi hai)
    if (i + 1 == j) {
        return 0;
    }
    
    int ans = INT_MAX;  // Initial answer ko maximum value se initialize karo
    
    // Har ek possible position k ke liye loop chalao
    for (int k = i + 1; k < j; k++) {
        // Minimum answer update karo
        ans = min(ans, (v[i] * v[j] * v[k] + solve_rec(v, i, k) + solve_rec(v, k, j)));
    }
    
    return ans;  // Minimum answer return karo
}



    int solve_rec_memo(vector<int>& v ,int i ,int j ,vector<vector<int>>& dp ){

        //bc
        if(i+1 == j ){
            return 0 ;
        }
        if(dp[i][j] != -1 ) return dp[i][j] ;


        int ans = INT_MAX ;

        for(int  k= i +1 ; k < j ; k ++ ){

            ans = min(ans ,( v[i] * v[j] * v[k]   +solve_rec_memo(v , i , k,dp ) + solve_rec_memo(v ,k , j ,dp) )) ;

        }

        dp[i][j] = ans ;

        return dp[i][j] ;

    }



    int solve_tabulisation(vector<int>& v ,int n  ){

        vector<vector<int>> dp(n , vector<int>(n, 0 ))  ;

        for(int i =n-1 ; i>= 0 ; i-- ){

            for(int j =i+2 ; j <n ;j ++ ){

                int ans = INT_MAX ;

                for(int k = i+1 ; k < j ;k ++ ){

                    ans = min(ans ,( v[i] * v[j] * v[k]   +dp[i][k] + dp[k][j]  )) ;

                }

                dp[i][j] = ans ;
            }


        }

        return dp[0][n-1] ;
    }


    int minScoreTriangulation(vector<int>& values) {


        int n = values.size() ;
        // return solve_rec(values , 0 , n-1 ) ;

        // vector<vector<int>> dp(n , vector<int>(n, -1)) ;
        // return solve_rec_memo(values ,0 ,n-1 ,dp ); 

        return solve_tabulisation(values , n );
    }


int main(){

    vector<int> val = {1,3,1,4,1,5 } ;

    cout << minScoreTriangulation(val) << endl;



}