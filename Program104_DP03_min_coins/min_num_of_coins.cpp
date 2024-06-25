//p104 -> dp03 -> min no. of coins. 
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int solve_rec(vector<int> &num, int x) {
    // base case
    // agar x 0 ho gaya to valid path h ye to  return 0
    if(x == 0 ){
        return  0;
    }
    // agar x negative ho gaya to invalid path h ye  return INT_MAX (infinity jaisa)
    if(x < 0 ){
        return INT_MAX ;
    }

    int mini = INT_MAX ;

    // har ek element ke liye check karenge

    for(int i = 0; i < num.size() ; i++ ){

        int ans = solve_rec(num , x - num[i]) ;

        // agar ans INT_MAX nahi hai to ans zero hoga ek valid path hoga mini ko update karenge

        if(ans != INT_MAX ){

            mini = min(mini , 1 + ans) ;

        }
    }

    return mini ;
}

int solve_rec_memo(vector<int> &num, int x, vector<int>& dp) {
    // base case
    // agar x 0 ho gaya to return 0
    if(x == 0 ){
        return  0;
    }
    // agar x negative ho gaya to return INT_MAX (infinity jaisa)
    if(x < 0 ){
        return INT_MAX ;
    }

    // agar dp mein x ka value already hai to usko return karenge
    if(dp[x] != -1){
        return dp[x] ;
    }

    int mini = INT_MAX ;

    // har ek element ke liye check karenge
    for(int i = 0; i < num.size() ; i++ ){
        int ans = solve_rec_memo(num , x - num[i] , dp) ;

        // agar ans INT_MAX nahi hai to mini ko update karenge
        if(ans != INT_MAX ){
            mini = min(mini , 1 + ans) ;
        }
    }
    dp[x] = mini ;
    return mini;
}

int solve_tabulation(vector<int> &num, int x) {
    vector<int> dp(x + 1, INT_MAX) ;

    dp[0] = 0 ;

    // tabulation method se har value ko calculate karenge
    for(int i = 1; i <= x; i++ ){
        for(int j = 0; j < num.size(); j++ ){
            if(i - num[j] >= 0 && dp[i - num[j]] != INT_MAX ){
                dp[i] = min(dp[i] , 1 + dp[i - num[j]]) ;
            }
        }
    }

    // agar dp[x] INT_MAX hai to return -1, warna dp[x] return karenge
    if(dp[x] == INT_MAX) return -1 ;
    return dp[x] ;
}

int minimumElements(vector<int> &num, int x) {
    // recursive method ko call kar sakte hain
    // int ans  = solve_rec(num , x) ;

    // ya memoization method ko call kar sakte hain
    // vector<int> dp(x + 1, -1) ;
    // int ans  = solve_rec_memo(num, x, dp) ;

    // agar ans INT_MAX hai to return -1, warna ans return karenge
    // if(ans == INT_MAX) return -1 ;
    // return ans ;

    // tabulation method ko call karenge
    return solve_tabulation(num, x);
}



int main(){


    vector<int> num = {1,2,3} ;
    int x =7 ;

    cout << minimumElements(num ,x ) << endl;

}