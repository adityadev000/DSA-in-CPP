//p118 -> dp17->  reducing dishes.


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int solve_rec(vector<int>& satisfaction, int index, int time, int n) {
    // Base case
    // Agar index n se bada ho gaya hai, to 0 return karo (koi element nahi bacha hai)
    if (index >= n) return 0;

    // Current item ko include karne se milne wali satisfaction
    int incl = satisfaction[index] * (time + 1) + solve_rec(satisfaction, index + 1, time + 1, n);

    // Current item ko exclude karke aage ke items ke saath satisfaction
    int excl = 0 + solve_rec(satisfaction, index + 1, time, n);

    // Maximum of include or exclude se milne wali maximum satisfaction return karo
    return max(incl, excl);
}



    int solve_rec_memo(vector<int>& satisfaction ,int index ,int time ,int n,vector<vector<int> >& dp ){
        //bc

        if(index >=  n) return 0; 

        if(dp[index][time] != -1 ) return dp[index][time] ;

        int incl = satisfaction[index]* (time +1 ) + solve_rec_memo(satisfaction ,index +1  , time +1 ,n ,dp   ) ;

        int excl = 0 + solve_rec_memo(satisfaction , index +1 ,time ,n ,dp ) ;

        return dp[index][time] =  max(incl , excl ) ;

    }

    int solve_tabulisation(vector<int>& satisfaction ,int n ){
        //bc
        vector<vector<int> > dp(n+1 , vector<int> (n+1 , 0 ) );

       for(int index =n-1 ;index >= 0;index -- ){

            for(int time = index ; time >= 0 ; time -- ){

                int incl = satisfaction[index]* (time +1 ) + dp[index+1][time+1] ;

                int excl = 0 + dp[index +1][time] ;

                dp[index][time] =  max(incl , excl ) ;

            }
       }
       return dp[0][0] ; 

    }


    int solve_opt(vector<int>& satisfaction ,int n ){
        //bc

        vector<int>curr(n+1 ,0 ) ;
        vector<int>next(n+1 ,0 ) ;

       for(int index =n-1 ;index >= 0;index -- ){

            for(int time = index ; time >= 0 ; time -- ){

                int incl = satisfaction[index]* (time +1 ) + next[time+1] ;

                int excl = 0 + next[time] ;

                curr[time] =  max(incl , excl ) ;

            }
            next = curr ;
       }
       return next[0] ; 

    }
    int maxSatisfaction(vector<int>& satisfaction) {
        
        sort(satisfaction.begin() , satisfaction.end()) ;
        int n = satisfaction.size() ;

        // return solve_rec(satisfaction ,0 , 0 , n) ; 

        // vector<vector<int> > dp(n+1 , vector<int> (n+1 , -1 ) )  ;
        // return solve_rec_memo(satisfaction ,0 ,0 , n ,dp ) ;

        // return solve_tabulisation(satisfaction ,n ) ;

        return solve_opt(satisfaction , n ) ;
    }



int main(){

    vector<int> s = {-1,-8,0,5,-9} ;

    cout << maxSatisfaction(s) << endl;


}