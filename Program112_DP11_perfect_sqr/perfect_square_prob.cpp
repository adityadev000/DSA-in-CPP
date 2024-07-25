//p112 -> dp11 ->  Get Minimum Squares.

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int solve_rec(int n) {
    // Base case
    // Agar n 0 hai, to 0 return karo (koi square sum nahi hai)
    if (n == 0) {
        return 0;
    }
    
    int ans = n;  // Answer ko initial me n se set karo
    
    // Har ek possible square sum ke liye loop chalao
    for (int i = 1; i * i <= n; i++) {
        // Agar n - i*i non-negative hai, to minimum answer update karo
        if (n - i * i >= 0) {
            ans = min(ans, 1 + solve_rec(n - i * i));
        }
    }
    
    return ans;  // Minimum square sum return karo
}

    
    int solve_rec_memo(int n , vector<int> & dp  ){
        
        //base case 
        if(n == 0 ){
            return  0; 
        }
        if(dp[n] != -1 ) return dp[n] ; 
        
        int ans =n ;
        for(int i =1; i*i <= n ; i ++ ) {
            
            if((n - i* i) >=0 ){
                ans = min(ans , 1+ solve_rec_memo(n - i*i ,dp  )) ; 
            }
        }
        dp[n] = ans ; 
        return dp[n] ; 
    }
    
    
    int solve_tabulisation(int n  ){
        
        
        vector<int>  dp(n+1 , INT_MAX) ; 
       
       dp[0] = 0 ;
        
        for(int i =1 ;i<= n ; i ++ ){
            
            
            for(int j =1; j*j <= n ; j ++ ) {
                
                if((i - j* j) >=0 ){
                    dp[i] = min(dp[i] , 1+ dp[i-j*j]) ; 
                }
            }
            
        }
 
        return dp[n] ; 
    }
    
	int MinSquares(int n)
	{
	    
	   // return solve_rec(n) ; 
	   
	   //vector<int> dp (n+1 , -1 );
	   //return solve_rec_memo( n ,dp ) ;
	   
	   return solve_tabulisation(n) ;
	   
	   
	}


int main(){

    cout << MinSquares(10) << endl;


}