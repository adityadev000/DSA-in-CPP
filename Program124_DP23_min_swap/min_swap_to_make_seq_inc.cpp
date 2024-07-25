//p124 -> dp23-> Min swap to make sequence incresing.
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int solve_rec(int i, vector<int>& nums1, vector<int>& nums2, bool swapped) {
    // Base case: agar index array ke size se bada ya equal ho jaye, to 0 return karo
    if (i >= nums1.size()) {
        return 0;
    }

    int ans = INT_MAX;  // Minimum answer ko initialize karo

    int prev1 = nums1[i - 1];  // Previous element in nums1
    int prev2 = nums2[i - 1];  // Previous element in nums2

    // Agar pichle step me swap hua tha to previous elements ko swap karo
    if (swapped) {
        swap(prev1, prev2);
    }

    // Agar current elements previous elements se bade hain (no swap case)
    if (nums1[i] > prev1 && nums2[i] > prev2) {
        // Swap nahi karte hain
        ans = solve_rec(i + 1, nums1, nums2, false);
    }

    // Agar current elements previous swapped elements se bade hain (valid swap case)
    if (nums1[i] > prev2 && nums2[i] > prev1) {
        // Swap karte hain aur minimum answer update karte hain
        ans = min(ans, 1 + solve_rec(i + 1, nums1, nums2, true));
    }

    // Final answer return karo
    return ans;
}


    int solve_rec_memo(int i , vector<int>& nums1, vector<int>& nums2 ,bool  swapped,vector<vector<int>>&dp ){

        if(i >= nums1.size() ){
            return 0; 
        }
        if(dp[i][swapped] != -1 ) return dp[i][swapped] ;

        int ans =INT_MAX ; 

        int prev1 = nums1[i-1] ;
        int prev2 = nums2[i-1] ;

        if(swapped){
            swap(prev1 ,prev2) ;
        }

        if(nums1[i] > prev1  &&  nums2[i] > prev2  ){
            //not swap 
            ans = solve_rec_memo(i+1 , nums1 ,nums2 , 0,dp ) ;

        }
        if(nums1[i] > prev2 && nums2[i] > prev1  ){ //valid swap.
            //swap 
            ans = min(ans , 1+ solve_rec_memo(i+1 , nums1 ,nums2 , 1,dp) ) ; 
        }

        return dp[i][swapped] = ans ;
    }

    int solve_tabulisation( vector<int>& nums1, vector<int>& nums2  ){

        vector<vector<int>>dp(nums1.size()+1  ,vector<int>(2,0)) ;
        
        int n = nums1.size() ;

        for(int i = n-1 ; i>=1 ;i --  ){

            for(int s = 1 ; s>=0  ; s -- ){

                int ans =INT_MAX ; 

                int prev1 = nums1[i-1] ;
                int prev2 = nums2[i-1] ;

                if(s){
                    swap(prev1 ,prev2) ;
                }

                if(nums1[i] > prev1  &&  nums2[i] > prev2  ){
                    //not swap 
                    ans = dp[i+1][0] ;

                }
                if(nums1[i] > prev2 && nums2[i] > prev1  ){ //valid swap.
                    //swap 
                    ans = min(ans , 1+ dp[i+1][1] ) ; 
                }

                dp[i][s] = ans ;

            }
        }

        return dp[1][0] ;

    }

    int solve_space_opt( vector<int>& nums1, vector<int>& nums2  ){

        // vector<vector<int>>dp(nums1.size()+1  ,vector<int>(2,0)) ;
        // vector<int> curr (2,0) ;
        // vector<int> next(2,0) ;
        int swapp = 0 ;
        int noswap =0 ;
        int currswap =0 ;
        int currnoswap =0 ;

        int n = nums1.size() ;

        for(int i = n-1 ; i>=1 ;i --  ){

            for(int s = 1 ; s>=0  ; s -- ){

                int ans =INT_MAX ; 

                int prev1 = nums1[i-1] ;
                int prev2 = nums2[i-1] ;

                if(s){
                    swap(prev1 ,prev2) ;
                }

                if(nums1[i] > prev1  &&  nums2[i] > prev2  ){
                    //not swap 
                    ans = noswap ;

                }
                if(nums1[i] > prev2 && nums2[i] > prev1  ){ //valid swap.
                    //swap 
                    ans = min(ans , 1+swapp ) ; 
                }

                if(s)
                    currswap = ans ;
                else currnoswap = ans ;

            }

            // next = curr ;
            swapp = currswap;
            noswap = currnoswap ;
        }

        return min(swapp , noswap)  ;

    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin() , -1);
        nums2.insert(nums2.begin() , -1);


        bool swapped = 0 ;
        // return  solve_rec(1 , nums1 ,nums2 ,swapped) ;

        // vector<vector<int>>dp(nums1.size()  ,vector<int>(2,-1)) ;
        // return  solve_rec_memo(1 , nums1 ,nums2 ,swapped , dp ) ;

        // return solve_tabulisation(nums1,nums2) ;

        return solve_space_opt(nums1,nums2) ;


    }


int main(){

    vector<int> nums1 = {0,4,4,5,9} ;

    vector<int> nums2 = {0,1,6,8,10} ; 

    cout << minSwap(nums1 ,nums2) << endl;


}