//p122 -> dp21->  Number of Dice Rolls with Target Sum
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

long long solve_rec(int i, int M, int N, int X) {
    // Base case: agar index N se bada ho jaye, to
    // agar X bhi 0 ho, to 1 return karo (solution mil gaya)
    // anyatha 0 return karo (solution nahi mila)
    if (i >= N) {
        if (X == 0) return 1;
        else return 0;
    }

    // Initial sum ko 0 se start karo
    int sum = 0;

    // Har ek dice ke liye recursion call karo
    for (int dice = 1; dice <= M; dice++) {
        sum += solve_rec(i + 1, M, N, X - dice);
    }

    // Total sum ko return karo
    return sum;
}

    long long solve_rec_memo(int i , int M , int N , int X ,vector<vector<long long>>& dp ){
        
        //bc
        // if(X < 0  ) return 0 ;
        
        // if(i == N && X != 0 ) return 0 ;
        
        // if(X == 0 && i != N ) return 0; 
        
        // if(i == N && X == 0 ) return 1 ;
        
        if(i >= N ){
            
            if(X == 0 ) return 1 ;
            
            else return 0; 
        }
            
        if(dp[i][X] != -1) return dp[i][X] ; 
        
        long long  sum =0 ;
        for(int dice = 1 ; dice <= M ; dice ++ ){
            
            if(X - dice >= 0) { // Check if X - dice is not negative
                sum += solve_rec_memo(i+1, M, N, X - dice, dp);
            }
        }
        
        return dp[i][X] = sum  ;
        
    }
    
    long long solve_tabulisation( int M , int N , int X  ){
        
        
        vector<vector<long long>> dp(N+1 , vector<long long>(X+1 , 0)) ;
        
        dp[N][0] = 1 ;
        
        
        for(int n =N-1  ; n >=0   ;n --    ){
            
            for(int x = 1 ; x <= X ; x ++ ){
                
                long long  sum =0 ;
                
                for(int dice = 1 ; dice <= M ; dice ++ ){
                    
                    if(x - dice >= 0) { // Check if X - dice is not negative
                    
                        sum += dp[n+1][x - dice] ;
                    }
                    
                }
                dp[n][x] = sum ; 
                
                
            }
        }
            
        
        return dp[0][X] ;
        
    }
    
    
    long long solve_space_opt( int M , int N , int X  ){
        
        
        vector<long long> curr(X+1 , 0 ) ;
        vector<long long> next(X+1 , 0 ) ;
        
        next[0] = 1 ;
        
        
        for(int n =N-1  ; n >=0   ;n --    ){
            
            for(int x = 1 ; x <= X ; x ++ ){
                
                long long  sum =0 ;
                
                for(int dice = 1 ; dice <= M ; dice ++ ){
                    
                    if(x - dice >= 0) { // Check if X - dice is not negative
                    
                        sum += next[x - dice] ;
                    }
                    
                }
                curr[x] = sum ; 
                
                
            }
            
            next = curr ;
        }
            
        
        return next[X] ;
        
    }
    long long noOfWays(int M , int N , int X) {
        
        
        // return solve_rec( 0, M , N , X    ) ;
        
        // vector<vector<long long>> dp(N , vector<long long>(X+1 , -1)) ;
        // return solve_rec_memo( 0, M , N , X ,dp   ) ;
        
        
        // return solve_tabulisation( M , N , X  ) ;
        
        
        return solve_space_opt( M , N , X  ) ;
        
    }


int main(){

    cout << noOfWays(6 ,3,12) << endl;


}