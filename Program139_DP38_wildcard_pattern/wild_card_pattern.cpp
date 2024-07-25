//p139 -> dp38-> Wild card pattern.  
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool solve_rec(string s, string p ,int i ,int j ){

    // Agar dono string aur pattern ke pointers zero se kam hain, to match ho gaya
    if(i < 0 && j< 0 ) return true ;

    // Agar string ka pointer valid hai lekin pattern ka pointer invalid hai, to match nahi ho sakta
    if(i >= 0 && j < 0 ) return false; 

    // Agar string ka pointer invalid hai lekin pattern ka pointer valid hai
    if(i < 0 && j >= 0 ) {

        // Pattern me agar koi non-'*' character hai, to match nahi ho sakta
        for(int k = 0 ; k <= j ;k ++ ){
            if(p[k] != '*') 
                return false ;
        }
        // Agar pattern me sirf '*' hai, to match ho sakta hai
        return true; 
    }

    // Agar current characters match hote hain ya pattern me '?' hai, to agle characters check karo
    if(s[i] == p[j] || p[j] == '?'){
        return solve_rec(s,p,i-1 , j-1 ) ;
    }

    // Agar pattern me '*' hai
    else if(p[j] == '*' ) {
        // '*' ek character ko match karta hai ya zero characters ko, dono possibilities check karo
        return (solve_rec(s ,p , i ,j-1)) || (solve_rec(s ,p , i-1 ,j)) ;
    }

    // Agar koi bhi match nahi ho raha hai, to false return karo
    else{
        return false ;
    }
}

    bool solve_rec_memo(string & s, string & p ,int i ,int j ,vector<vector<int>>& dp){

        if(i < 0 && j< 0 ) return true ;

        if(i>= 0 && j<0 ) return false; 

        if(i < 0 && j>=0 ) {

            for(int k = 0 ; k <= j ;k ++ ){
                if(p[k] != '*') 
                    return false ;
                
            }
            return true; 
        }
        if(dp[i][j] != -1 ) return dp[i][j] ; 


        if(s[i] == p[j] || p[j] == '?'){

            return dp[i][j] =  solve_rec_memo(s,p,i-1 , j-1 ,dp  ) ;
        }

        else if(p[j] == '*' ) {

            return dp[i][j] =  (solve_rec_memo(s ,p , i ,j-1 ,dp )) || (solve_rec_memo(s ,p , i-1 ,j ,dp )) ;

            // return dp[i][j] =  true ;
        }
        else{
            return dp[i][j] =  false ;
        }
    }
    bool solve_tabulisation(string  s, string p ){

        int n = s.length() ;
        int m = p.length() ;
        vector<vector<int>> dp(n+1 , vector<int> (m+1 ,0 ));

        dp[0][0] =true ;

        for(int j =1 ; j <= m ;j ++ ){
            bool flag = true ;

            for(int k = 1 ; k <= j ;k ++ ){

                if(p[k-1] != '*') {

                    flag = false ;
                    break ;
                }
            }
            dp[0][j] = flag ; 
        }

        for(int i =1 ; i <= n ;i ++ ){

            for(int j =1 ;j<= m ; j++ ) {


                if(s[i-1] == p[j-1] || p[j-1] == '?'){

                    dp[i][j] =  dp[i-1][j-1] ;
                }

                else if(p[j-1] == '*' ) {

                    dp[i][j] = ( dp[i][j-1] || dp[i-1][j]) ;

                }
                else{
                    dp[i][j] =  false ;
                }
            }
        }
        return dp[n][m] ; 
    }
    
    bool solve_space_opt(string  s, string p ){

        int n = s.length() ;
        int m = p.length() ;
        // vector<vector<int>> dp(n+1 , vector<int> (m+1 ,0 ));

        vector<int> prev(m+1 ,0) ;
        vector<int> curr(m+1 ,0) ;

        prev[0] =true ;

        for(int j =1 ; j <= m ;j ++ ){
            bool flag = true ;

            for(int k = 1 ; k <= j ;k ++ ){

                if(p[k-1] != '*') {

                    flag = false ;
                    break ;
                }
            }
           prev[j] = flag ; 
        }

        for(int i =1 ; i <= n ;i ++ ){

            for(int j =1 ;j<= m ; j++ ) {


                if(s[i-1] == p[j-1] || p[j-1] == '?'){

                    curr[j] =  prev[j-1] ;
                }

                else if(p[j-1] == '*' ) {

                    curr[j] = ( curr[j-1] || prev[j]) ;

                }
                else{
                    curr[j] =  false ;
                }
            }

            prev= curr ;
        }
        return prev[m] ; 
    }
    bool isMatch(string s, string p) {
        
        int n = s.length() ;
        int m = p.length() ;

        // return solve_rec(s , p , n-1 ,m-1  ) ;

        // vector<vector<int>> dp(n , vector<int> (m ,-1 )) ;
        // return solve_rec_memo(s ,p , n-1 ,m-1 ,dp ) ;

        // return solve_tabulisation(s ,p ) ;

        return solve_space_opt(s ,p ) ;
    }


int main(){

    string s = "abcde";
    string p = "a*c?e" ;

    cout <<  solve_space_opt(s ,p ) << endl ;


}