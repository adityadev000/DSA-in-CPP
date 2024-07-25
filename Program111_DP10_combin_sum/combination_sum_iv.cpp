//p111 -> dp10 ->   Combination Sum IV
#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int solve_rec(vector<int>& num, int tar) {
    // base case
    // Agar target 0 hai, to 1 return karo (ek valid combination milti hai)
    if (tar == 0) {
        return 1;
    }
    
    // Agar target negative ho gaya hai, to 0 return karo (koi valid combination nahi hai)
    if (tar < 0) {
        return 0;
    }

    int ans = 0;  // Answer ko initial me 0 set karo
    
    // Har ek number num[i] ke liye loop chalao
    for (int i = 0; i < num.size(); i++) {
        // Tar se num[i] subtract karke recursion call karo aur answer ko add karo
        ans += solve_rec(num, tar - num[i]);
    }
    
    return ans;  // Answer return karo (total combinations jo target sum bana sakte hain)
}


int solve_rec_memo (vector<int> &num, int tar ,vector<int>& dp  ){

    //base case
    if(tar == 0 ){

        return 1  ;
    }
    if(tar < 0 ) return 0 ;
    if(dp[tar] != -1 ) return dp[tar] ; 
    
    int ans  =0; 

    for(int i =0 ; i< num.size(); i ++ ){

        ans += solve_rec_memo(num , tar - num[i] ,dp   ) ;
        
    }

    dp[tar] = ans ;

    return dp[tar] ;
}

int solve_tabulisation (vector<int> &num, int tar  ){

    vector<int> dp(tar+1 ,0 );

    dp[0] =1 ;

    for(int i =1 ;i<= tar ; i++ ){

        for(int j =0 ; j< num.size(); j ++ ){

            if(i - num[j] >=0 ) 
            dp[i] += dp[i - num[j]] ;
            
        }
    }


    return dp[tar] ;
}
int findWays(vector<int> &num, int tar)
{
    // return solve_rec(num , tar ); 


    // vector<int> dp(tar+1 ,-1 );
    // return solve_rec_memo(num , tar , dp ) ;

    return solve_tabulisation(num ,tar ) ;

    //sapce opt is not possible.

}


int main(){

    vector<int> num = {1,2,5 };

    cout << findWays(num , 5) << endl;


}