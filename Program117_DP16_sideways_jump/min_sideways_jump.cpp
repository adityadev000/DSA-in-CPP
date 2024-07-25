//p117 -> dp16->  Minimum Sideways Jump. 

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int solve_rec(vector<int>& obstacles, int curr_lane, int curr_pos) {
    // Base case
    // Agar current position last obstacle ke position ke equal hai, to 0 return karo (koi obstacle nahi bacha hai)
    if (curr_pos == obstacles.size() - 1) return 0;

    // Agar next lane different hai
    if (curr_lane != obstacles[curr_pos + 1]) {
        return solve_rec(obstacles, curr_lane, curr_pos + 1);  // Next position ke saath recursion call karo
    } else {
        // Agar next lane same hai
        int ans = INT_MAX;

        // Teen alag lanes ke liye loop chalao
        for (int i = 1; i <= 3; i++) {
            // Agar i current lane ya next obstacle lane nahi hai
            if (i != curr_lane && i != obstacles[curr_pos]) {
                ans = min(ans, 1 + solve_rec(obstacles, i, curr_pos));  // Minimum moves calculate karo
            }
        }

        return ans;  // Minimum moves return karo
    }
}



    int solve_rec_memo(vector<int>& obstacles ,int curr_lane ,int curr_pos ,vector<vector<int>> &dp){
        //bc
        if(curr_pos == obstacles.size() -1 ) return 0 ;

        if(dp[curr_lane][curr_pos] != -1 ) return dp[curr_lane][curr_pos] ; 
 
        if(curr_lane != obstacles[curr_pos +1]){
            return solve_rec_memo(obstacles , curr_lane , curr_pos+1 ,dp ) ;
        }

        else{
            
            int ans =INT_MAX ;
            for(int i =1 ;i <= 3 ; i++ ){

                if(i != curr_lane && i != obstacles[curr_pos] ) {

                    ans = min(ans , 1 + solve_rec_memo(obstacles , i , curr_pos ,dp ) ) ;

                }
            }
            dp[curr_lane][curr_pos] = ans ;
            return dp[curr_lane][curr_pos] ;
        }
        
    }

    int solve_tabulisation(vector<int> & obstacles ){
        int n = obstacles.size() -1 ;
        vector<vector<int>> dp(4 , vector<int> (n+1 , 1e9 )) ;

        dp[0][n] = 0 ;
        dp[1][n] = 0 ;
        dp[2][n] = 0 ;
        dp[3][n] = 0 ; 

        for(int curr_pos = n-1 ;curr_pos >= 0 ;curr_pos -- ){

            for(int curr_lane = 1 ;curr_lane <= 3 ;curr_lane ++ ){

                if(curr_lane != obstacles[curr_pos +1]){

                    dp[curr_lane][curr_pos] =  dp[curr_lane][curr_pos+1 ] ;

                }

                else{
                    
                    int ans =1e9 ;
                    for(int i =1 ;i <= 3 ; i++ ){

                        if(i != curr_lane && i != obstacles[curr_pos] ) {

                            ans = min(ans , 1 + dp[i][curr_pos+1] ) ;

                        }

                        dp[curr_lane][curr_pos] = ans ; 
                    }
                }

            }

        }

        return min(dp[2][0] ,  min(1+dp[1][0] , 1 + dp[3][0])) ;

    }


    int solve_opt(vector<int> & obstacles ){
        int n = obstacles.size() -1 ;
        vector<vector<int>> dp(4 , vector<int> (n+1 , 1e9 )) ;

        vector<int> curr(4 , INT_MAX) ;
        vector<int> next(4 , INT_MAX) ;

        next[0] = 0 ;
        next[1] = 0 ;
        next[2] = 0 ;
        next[3] = 0 ; 

        for(int curr_pos = n-1 ;curr_pos >= 0 ;curr_pos -- ){

            for(int curr_lane = 1 ;curr_lane <= 3 ;curr_lane ++ ){

                if(curr_lane != obstacles[curr_pos +1]){

                    curr[curr_lane] =  next[curr_lane] ;

                }

                else{
                    
                    int ans =1e9 ;
                    for(int i =1 ;i <= 3 ; i++ ){

                        if(i != curr_lane && i != obstacles[curr_pos] ) {

                            ans = min(ans , 1 + next[i] ) ;

                        }

                        curr[curr_lane] = ans ; 
                    }
                }

            }

            next = curr ;

        }

        return min(next[2] ,  min(1+next[1] , 1 + next[3])) ;

    }
    int minSideJumps(vector<int>& obstacles) {
        
        int n = obstacles.size() ;

        // return solve_rec(obstacles , 2 , 0 ) ;

        // vector<vector<int>> dp(4 , vector<int> (n , -1 )) ; 
        // return solve_rec_memo(obstacles , 2, 0, dp ) ;

        // return solve_tabulisation(obstacles) ;

        return solve_opt(obstacles);


    }


int main (){

    vector<int> obs = {0,2,1,0,3,0 } ;

    cout << minSideJumps(obs) << endl;
}