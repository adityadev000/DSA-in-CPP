//p119-> dp18->  longest increasing subsequence.
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

    int solve_rec(int n , int a[] , int curr , int prev ){

        if(curr >= n ) return 0 ; 

        //include 
        int incl = 0 ;
        if(prev == -1 || a[curr] > a[prev] ){
            incl = 1 + solve_rec(n , a , curr + 1 , curr ) ;
        }

        //exclude

        int excl = 0 + solve_rec(n ,a , curr +1 , prev ) ;

        return max(incl , excl ) ;
    }
    
    int solve_rec_memo(int n , int a[] , int curr , int prev,vector<vector<int>>  dp ){

        if(curr == n ) return 0 ; 

        if(dp[curr][prev+1] != -1  ) return dp[curr][prev+1] ;

        //include 
        int incl = 0 ;
        if(prev == -1 || a[curr] > a[prev] ){
            incl = 1 + solve_rec_memo(n , a , curr + 1 , curr ,dp ) ;
        }

        //exclude

        int excl = 0 + solve_rec_memo(n ,a , curr +1 , prev ,dp ) ;

        return dp[curr][prev+1] =  max(incl , excl ) ;
    }
    
     int solve_tabulisation (int n, int a[]){
         
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int curr = n-1; curr>=0; curr--){
            
            for(int prev = curr-1; prev>=-1; prev--){
                
                // include
                int incl = 0;
                if(prev == -1 || a[curr] > a[prev])
                    incl = 1 + dp[curr+1][curr+1];
                    
                // exclude
                int excl = 0 + dp[curr+1][prev+1];
                
                dp[curr][prev+1] = max(incl, excl);
            }
        }
        
        return dp[0][0];
    }
    
    
    int solve_space_opt (int n, int a[]){
         
        vector<int> curr_r (n+1 , 0 ) ;
        vector<int> next_r(n+1 , 0 ) ;
        
        for(int curr = n-1; curr>=0; curr--){
            
            for(int prev = curr-1; prev>=-1; prev--){
                
                // include
                int incl = 0;
                if(prev == -1 || a[curr] > a[prev])
                    incl = 1 + next_r[curr+1];
                    
                // exclude
                int excl = 0 + next_r[prev+1];
                
                curr_r[prev+1] = max(incl, excl);
            }
            
            next_r  = curr_r ; 
        }
        
        return next_r[0];
    }
    
int solve_optimised(int n, int a[]){
    // Base case: agar n 0 hai, to 0 return karo (koi element nahi hai)
    if(n == 0)
        return 0;
        
    vector<int> ans;  // Ek vector jo increasing subsequence ko store karega
    ans.push_back(a[0]);  // Pehle element se sequence ko initialize karo
    
    for(int i=1; i<n; i++){
        // Agar current element ans ke last element se bada hai
        if(a[i] > ans.back())
            ans.push_back(a[i]);  // Current element ko ans ke end mein daalo
        else{
            // Ans mein a[i] se bada smallest element ka index dhoondo
            int index = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
            ans[index] = a[i];  // Us index par a[i] ko daal do
        }
    }
    
    return ans.size();  // Ans ka size return karo, jo longest increasing subsequence ka length hai
}

    int longestSubsequence(int n, int a[])
    {
    //    return solve_rec( n , a , 0 ,-1 );

        // vector<vector<int>>  dp(n , vector <int> (n+1 , -1 ) ) ;
        // return solve_rec_memo(n ,a ,0, -1 , dp ) ;
        
        // return solve_tabulisation(n , a) ;
        
        // return solve_space_opt(n ,a) ; 
        
        return solve_optimised(n ,a ) ;


    }


int main(){

    int a[16] = {0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15} ;

    cout << longestSubsequence(16 , a ) << endl;


}