//p125 -> dp24-> Length of longest Ap.
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int solve_rec(int index, int diff, int* A) {
    // Base case: agar index 0 se chhota ho, to 0 return karo
    if (index < 0) return 0;
    
    int ans = 0;
    
    // Har possible previous element ke liye check karo
    for (int j = index - 1; j >= 0; j--) {
        // Agar current element aur previous element ka difference equal hai
        if (A[index] - A[j] == diff) {
            // Maximum answer ko update karo
            ans = max(ans, 1 + solve_rec(j, diff, A));
        }
    }
    
    // Final answer return karo
    return ans;
}

    
    int solve_rec_memo(int index , int diff , int* A,unordered_map<int,int>dp[]) {
        
        if(index < 0 ) return 0 ;
        if(dp[index].count(diff) ) return dp[index][diff] ;
        
        int ans =0 ;
        for(int j = index -1 ; j>=0 ; j-- ){
            
            if(A[index] - A[j] == diff ){
                
                ans = max(ans , 1+ solve_rec_memo(j , diff , A ,dp)) ;
            }
        }
        return dp[index][diff] =  ans ;
    }

    int lengthOfLongestAP(int A[], int n) {
    
    
        if(n <= 2 ) return n ;
        
/*
        unordered_map<int,int> dp[n+1] ;
        int ans  =0 ;
        for(int i =0 ;i < n ;i++ ){
            
            for(int j =i+1 ; j<n ;j ++ ){
                
                // ans = max(ans , 2 +solve_rec(i , A[j] -A[i] , A)) ;
                ans = max(ans , 2 +solve_rec_memo(i , A[j] -A[i] , A,dp)) ;
            }
        }
        return ans ;
        
*/     
        
        //tabulisatuion
        
        unordered_map<int,int> dp[n+1] ;
        int ans  =0 ;
        
        for(int i =1 ;i <n ;i ++ ){
            
            for(int j =0 ; j< i; j++ ){
                
                int diff = A[i] - A[j] ;
                
                int cnt =1 ;
                
                if(dp[j].count(diff) ){
                    cnt = dp[j][diff] ;
                }
                
                dp[i][diff] = cnt +1 ;
                
                ans = max(ans , dp[i][diff]) ;
            }
        }
        
        return ans; 
        
    }


int main(){

    int A[6] = {1, 7, 10, 13, 14, 19} ;

    cout << lengthOfLongestAP(A , 6) << endl;


}