//p135 -> dp34-> longest common subsequence.
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int solve_rec(int i, int j, string text1, string text2) {

    // Base case: agar kisi string ka end aa gaya, return 0
    if (i >= text1.length() || j >= text2.length()) return 0;

    // Agar current characters match karte hain
    if (text1[i] == text2[j]) {
        // Dono ko aage badhao aur 1 add kar do
        return 1 + solve_rec(i + 1, j + 1, text1, text2);
    } else {
        // Nahi match karte to max value return karo:
        // Ya to text1 ka index aage badhao
        // Ya text2 ka index aage badhao
        return max(solve_rec(i + 1, j, text1, text2), solve_rec(i, j + 1, text1, text2));
    }
}


    int solve_rec_memo(int i , int j ,string text1, string text2,vector<vector<int>>& dp ){

        //bc
        if( i >= text1.length() || j >= text2.length() ) return 0 ;
        if(dp[i][j] != -1 ) return dp[i][j] ;
        
        int ans =0 ;
        if(text1[i] == text2[j] ) {
            ans =  1+ solve_rec_memo(i+1 , j+1 , text1 , text2,dp ) ;
        }

        else{
            ans =  max( solve_rec_memo(i+1 , j , text1 ,text2 ,dp) , solve_rec_memo(i ,j+1 , text1 ,text2 ,dp) ) ;
        }

        return dp[i][j] = ans ;
    }
    int solve_tabulisation(string text1, string text2 ){

        int n = text1.length() ;
        int m = text2.length() ;
        vector<vector<int>> dp(n+1 , vector<int> (m+1 , 0 )) ;

        for(int i = n-1 ; i>=0 ;i-- ){

            for(int j = m-1 ;j>=0 ;j -- ){

                if(text1[i] == text2[j] ) {
                    dp[i][j] =  1+ dp[i+1][j+1] ;
                }

                else{
                    dp[i][j] =  max( dp[i+1][j] , dp[i][j+1] ) ;
                }

            }
        }

        return dp[0][0] ;
    }
    int solve_space_opt(string text1, string text2 ){

        //bc
        int n = text1.length() ;
        int m = text2.length() ;
        // vector<vector<int>> dp(n+1 , vector<int> (m+1 , 0 )) ;

        vector<int> curr(m+1 , 0 );
        vector<int> next(m+1 , 0 );

        for(int i = n-1 ; i>=0 ;i-- ){

            for(int j = m-1 ;j>=0 ;j -- ){

                if(text1[i] == text2[j] ) {
                    curr[j] =  1+ next[j+1] ;
                }

                else{
                    curr[j] =  max( next[j] , curr[j+1] ) ;
                }

            }
            next = curr ;
        }

        return next[0] ;
    }
    int longestCommonSubsequence(string text1, string text2) {
        // return solve_rec(0 , 0 , text1 , text2 ) ;

        int n = text1.length() ;
        int m = text2.length() ;
        // vector<vector<int>> dp(n , vector<int> (m , -1 )) ;
        // return solve_rec_memo(0 , 0 , text1 , text2 ,dp ) ;

        // return solve_tabulisation(text1 ,text2) ;

        return solve_space_opt(text1 ,text2) ;
    }


int main(){
    string s = "abcde" ;
    string ss = "ace" ;
    cout <<longestCommonSubsequence(s ,ss )  << endl;


}