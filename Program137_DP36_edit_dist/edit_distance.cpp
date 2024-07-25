//p137 -> dp36-> Edit distance -> minimum number of operations required to convert word1 to word2.
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int solve_rec(string a, string b, int i, int j) {
    // Base case
    // If we've reached the end of string 'a', return the number of remaining characters in 'b'
    if (i == a.length()) return b.length() - j;

    // If we've reached the end of string 'b', return the number of remaining characters in 'a'
    if (j == b.length()) return a.length() - i;

    // If the current characters of 'a' and 'b' match
    if (a[i] == b[j]) {

        // Move to the next character in both strings
        return solve_rec(a, b, i + 1, j + 1);

    } else {

        // If the characters do not match, consider all three operations:

        // 1. Insert a character (move forward in string 'b')
        int insert_ans = 1 + solve_rec(a, b, i, j + 1);

        // 2. Delete a character (move forward in string 'a')
        int delete_ans = 1 + solve_rec(a, b, i + 1, j);
        
        // 3. Replace a character (move forward in both strings)
        int replace_ans = 1 + solve_rec(a, b, i + 1, j + 1);

        // Return the minimum of the three operations
        return min(insert_ans, min(delete_ans, replace_ans));
    }
}
    int solve_rec_memo(string a ,string b , int i ,int j ,vector<vector<int>> &dp) {
        //bc
        if(i == a.length() ) return b.length() - j ;
        if(j == b.length() ) return a.length() - i ;
        if(dp[i][j] != -1 ) return dp[i][j] ; 


        if(a[i] == b[j] ){
            return dp[i][j] =  solve_rec_memo(a,b, i+1 ,j+1 , dp ) ;
        }

        else{

            int insert_ans = 1+  solve_rec_memo(a,b , i ,j+1 , dp ) ;
            int delete_ans = 1+  solve_rec_memo(a,b , i+1,j , dp ) ;
            int replace_ans = 1+  solve_rec_memo(a,b , i+1,j+1  , dp ) ;

            return dp[i][j] =  min(insert_ans , min(delete_ans , replace_ans)) ;

        }
    }

    int solve_tabulisation(string a ,string b) {
        //bc
        int n =a.length() ;
        int m = b.length() ;
        vector<vector<int>> dp (n+1, vector<int> (m +1, 0) ) ;
        for(int x = 0 ;x <= m ;x ++  ){
            dp[n][x] = b.length() - x ;
        }
        for(int x = 0 ;x <= n ;x ++  ){
            dp[x][m] = a.length() - x ;
        }


        for(int i = n-1 ;i >=0 ; i-- ){

            for(int j = m-1 ; j >=0 ;j -- ){

                if(a[i] == b[j] ){
                    dp[i][j] =  dp[i+1][j+1] ;
                }

                else{

                    int insert_ans = 1+  dp[i][j+1] ;
                    int delete_ans = 1+  dp[i+1][j] ;
                    int replace_ans = 1+  dp[i+1][j+1] ;

                    dp[i][j] =  min(insert_ans , min(delete_ans , replace_ans)) ;

                }
            }
        }
        return dp[0][0] ; 
    }
    int solve_space_opt(string a ,string b) {
        //bc
        int n =a.length() ;
        int m = b.length() ;
        // vector<vector<int>> dp (n+1, vector<int> (m +1, 0) ) ;
        vector<int> curr(m+1 , 0 ) ; 
        vector<int> next (m+1 , 0 ) ;
         
        for(int x = 0 ;x <= m ;x ++  ){
            next[x] = b.length() - x ;
        }


        // for(int x = 0 ;x < 2  ;x ++  ){
        //     dp[x][m] = a.length() - x ;
        // }


        for(int i = n-1 ;i >=0 ; i-- ){

            for(int j = m-1 ; j >=0 ;j -- ){

                //catch base case
                curr[m] = a.length() - i ; 

                if(a[i] == b[j] ){
                    curr[j] =  next[j+1] ;
                }

                else{

                    int insert_ans = 1+  curr[j+1] ;
                    int delete_ans = 1+  next[j] ;
                    int replace_ans = 1+  next[j+1] ;

                    curr[j] =  min(insert_ans , min(delete_ans , replace_ans)) ;

                }
            }

            next = curr ;
        }
        return next[0] ; 
    }
    int minDistance(string word1, string word2) {

        // return solve_rec(word1 ,word2 , 0 ,0 ) ;

        int n =word1.length() ;
        int m = word2.length() ;
        // vector<vector<int>> dp (n, vector<int> (m , -1) ) ;
        // return solve_rec_memo(word1 ,word2 , 0 ,0, dp ) ;

        // return solve_tabulisation(word1 , word2) ;

        if(n == 0 ) return m ;
        if(m == 0) return n ;
        return solve_space_opt(word1 , word2) ;
    }


int main(){

    string s = "horse" ;
    string p = "ros" ;

    cout << minDistance(s ,p ) << endl;


}