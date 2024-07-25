//p121 -> dp20->  pizza with 3n slices.
#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int solve_rec(int s, int e, vector<int>& slices, int n) {
    // Base case: agar n 0 ho ya s end se bada ho jaye, to 0 return karo
    if (n == 0 || s > e) {
        return 0;
    }

    // Current slice ko include karke solve karo (current slice ke baad se start karo)
    int incl = slices[s] + solve_rec(s + 2, e, slices, n - 1);

    // Current slice ko exclude karke solve karo (next slice se start karo)
    int excl = 0 + solve_rec(s + 1, e, slices, n);

    // Maximum of include or exclude ko return karo
    return max(incl, excl);
}


    int solve_rec_memo(int s ,int e ,vector<int>& slices , int n ,vector<vector<int>> &dp ){
        //bc
        if(n == 0 || s > e ) {
            return 0 ;
        }
        if(dp[s][n] != -1 ) return dp[s][n] ;

        int incl = slices[s] + solve_rec_memo(s+2 , e , slices , n -1 ,dp ) ;
        int excl = 0 + solve_rec_memo(s+1 , e , slices , n,dp) ;

        return dp[s][n] =  max(incl , excl) ;
    }

    int solve_tabulisation(vector<int>& slices ,int k ){
        
        vector<vector<int>> dp1(k+2 ,vector<int> ((k/3)+1  , 0 )) ;
        vector<vector<int>> dp2(k+2 ,vector<int> ((k/3)+1  , 0 )) ;

        for(int s = k-2  ; s >= 0 ; s-- ){

            for(int n = 1 ; n <= k/3 ; n++ ){

                int incl = slices[s] + dp1[s+2][n-1] ;
                int excl = 0 + dp1[s+1][n]  ;
                dp1[s][n] =  max(incl , excl) ;

            }
        }
        for(int s = k-1  ; s >= 1 ; s-- ){

            for(int n = 1 ; n <= k/3 ; n++ ){
                int incl = slices[s] + dp2[s+2][n-1] ;
                int excl = 0 + dp2[s+1][n]  ;
                dp2[s][n] =  max(incl , excl) ;

            }
        }

        return max(dp1[0][k/3] , dp2[1][k/3]) ;

    }

    int solve_space_opt(vector<int>& slices ,int k ){
        

        vector<int> row1_1 (k/3 +1 , 0 ) ;
        vector<int> row2_1 (k/3 +1 , 0 ) ;
        vector<int> row3_1 (k/3 +1 , 0 ) ;

        vector<int> row1_2 (k/3 +1 , 0 ) ;
        vector<int> row2_2 (k/3 +1 , 0 ) ;
        vector<int> row3_2 (k/3 +1 , 0 ) ;

        for(int s = k-2  ; s >= 0 ; s-- ){

            for(int n = 1 ; n <= k/3 ; n++ ){

                int incl = slices[s] +row3_1[n-1] ;
                int excl = 0 + row2_1[n]  ;
                row1_1[n] =  max(incl , excl) ;

            }

            row3_1 = row2_1 ;
            row2_1 = row1_1 ;
        }
        for(int s = k-1  ; s >= 1 ; s-- ){

            for(int n = 1 ; n <= k/3 ; n++ ){
                int incl = slices[s] + row3_2[n-1] ;
                int excl = 0 + row2_2[n]  ;
                row1_2[n] =  max(incl , excl) ;

            }
            row3_2 = row2_2 ;
            row2_2 = row1_2 ;

        }

        return max(row1_1[k/3] , row1_2[k/3]) ;

    }
    int maxSizeSlices(vector<int>& slices) {
        int k =slices.size() ; 

        // int case1 = solve_rec(0 , k-2 ,slices , k/3 ) ;
        // int case2 = solve_rec(1 , k-1 ,slices , k/3 ) ;
        // return max(case1 ,case2) ;


        // vector<vector<int>> dp1(k ,vector<int> ((k/3)+1  , -1 )) ;
        // int case1 = solve_rec_memo(0 , k-2 ,slices , k/3,dp1 ) ;

        // vector<vector<int>> dp2(k ,vector<int> ((k/3)+1  , -1 )) ;
        // int case2 = solve_rec_memo(1 , k-1 ,slices , k/3 ,dp2) ;

        // return max(case1 ,case2) ;

        // return solve_tabulisation(slices ,k ); 

        return solve_space_opt(slices , k ) ;
    }


int main(){

    vector<int> slices = {8,9,8,6,1,1} ; 

    cout << maxSizeSlices(slices)  << endl;


}