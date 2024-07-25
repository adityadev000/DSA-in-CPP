//p115 -> dp14->  Largest square formed in a matrix

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int solve_rec(vector<vector<int>>& mat, int i, int j, int& maxi) {
    // Base case
    // Agar i ya j matrix ke size se bada ho gaya hai, to 0 return karo (koi element nahi hai)
    if (i >= mat.size() || j >= mat[0].size()) {
        return 0;
    }

    // Right direction se maximum consecutive ones calculate karo
    int right = solve_rec(mat, i, j + 1, maxi);

    // Diagonal direction se maximum consecutive ones calculate karo
    int diagonal = solve_rec(mat, i + 1, j + 1, maxi);

    // Down direction se maximum consecutive ones calculate karo
    int down = solve_rec(mat, i + 1, j, maxi);

    // Agar current position par 1 hai
    if (mat[i][j] == 1) {
        // Current position se shuru ho kar minimum of right, diagonal, ya down direction me se ek chuno aur 1 add karo
        int ans = 1 + min(right, min(diagonal, down));

        // Maximum consecutive ones ko update karo
        maxi = max(maxi, ans);

        return ans;  // Answer return karo
    } else {
        return 0;  // Agar current position par 0 hai, to 0 return karo
    }
}


    int solve_rec_memo(vector<vector<int>>&  mat ,int i ,int j,int & maxi , vector<vector<int> >& dp ) {

        if(i >= mat.size() || j>= mat[0].size() ){
            return 0; 
        }
        if(dp[i][j] != -1 ) return dp[i][j] ; 

        int right = solve_rec_memo(mat ,i ,j+1 ,maxi ,dp) ;
        int diagonal = solve_rec_memo(mat , i+1 ,j +1,maxi ,dp) ;
        int down = solve_rec_memo(mat , i+1 ,j ,maxi,dp) ;

        if(mat[i][j] ==1 ){

            dp[i][j] = 1 + min (right ,min(diagonal ,down )) ;

            maxi = max(maxi ,dp[i][j] ); 

            return dp[i][j] ;

        }
        else return 0 ;

    }


    int solve_tabulisation(vector<vector<int>>&  mat ,int & maxi ,int n ,int m ) {

        vector<vector<int> > dp(n+1 ,vector<int>(m+1, 0)) ;

        for(int i = n-1; i>=0  ; i-- ){

            for(int j = m-1;  j>=  0  ; j-- ){
                
                int right = dp[i][j+1] ;
                int diagonal = dp[i+1][j+1] ;
                int down = dp[i+1][j] ;


            if(mat[i][j] ==1 ){

                dp[i][j] = 1 + min (right ,min(diagonal ,down )) ;

                maxi = max(maxi ,dp[i][j] ); 



            }
            else dp[i][j] =  0 ;

            }
        }
        return dp[0][0] ; 

    }

    int solve_opt(vector<vector<int>>&  mat ,int & maxi ,int n ,int m ) {

        vector<int> curr (m+1 , 0 );
        vector<int> next (m+1 , 0 );

        for(int i = n-1; i>=0  ; i-- ){

            for(int j = m-1;  j>=  0  ; j-- ){
                
                int right = curr[j+1] ;
                int diagonal = next[j+1] ;
                int down = next[j] ;


            if(mat[i][j] ==1 ){

                curr[j] = 1 + min (right ,min(diagonal ,down )) ;

                maxi = max(maxi ,curr[j] ); 



            }
            else curr[j] =  0 ;

            }

            next = curr ; 
        }
        return curr[0] ; 

    }
    int maxSquare(int n, int m, vector<vector<int>> mat){
        
        int maxi =0 ;
        
        // solve_rec(mat ,0 ,0,maxi  ) ;
        
        // vector<vector<int> > dp(n ,vector<int>(m, -1)) ;
        // solve_rec_memo(mat ,0 ,0 , maxi ,dp ) ;
        
        
        // solve_tabulisation(mat , maxi ,n ,m ) ;
        
        solve_opt(mat , maxi ,n ,m ) ;
        return maxi ;
    }


int main(){

    int n = 2, m=2 ; 
    vector<vector<int>> mat = {{1, 1}, {1, 1}} ;

    cout << maxSquare(n ,m, mat ) << endl;

}