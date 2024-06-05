//find permutation.
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void solve (vector<int> nums , vector<vector<int>>& ans ,int i ){
        //base case 
        if(i>= nums.size()){
            ans.push_back(nums) ;
            return  ;
        }
        for(int j =i ;j < nums.size() ; j++ ){
            swap(nums[i] , nums[j] ) ;
            solve(nums ,ans , i+1) ;
            //backtracking 
            swap(nums[i] , nums[j] ) ; //swap again to neutralise the effect ;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans ;
        int i = 0; 
        solve(nums ,ans , i) ;
        return ans  ;
    }

int main(){

    vector<int> nums ={1,2,3} ;
    vector<vector<int>> ans = permute(nums) ;

    for(int i = 0; i< ans.size() ; i++){
        for(int j = 0; j< ans[0].size() ; j++){
            cout << ans[i][j] << " ";
        }
        cout  << endl;
    }


}