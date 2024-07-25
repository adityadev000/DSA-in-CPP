//p126 -> dp25-> Length of longest Ap with common diff d.
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int longestSubsequence(vector<int>& arr, int difference) {
    unordered_map<int, int> dp;  // Map to store the longest subsequence length ending with a specific element
    int ans = 0; 

    for (int i = 0; i < arr.size(); i++) {
        int element = arr[i] - difference;  // Calculate the previous element in the subsequence
        int t_ans = 1;  // Initialize the current subsequence length

        // Agar previous element map mein hai, to current subsequence length update karo
        if (dp.count(element)) {
            t_ans += dp[element];
        }

        dp[arr[i]] = t_ans;  // Update the map with the current element's subsequence length
        ans = max(ans, dp[arr[i]]);  // Update the final answer with the maximum subsequence length
    }

    return ans;  // Return the length of the longest subsequence
}



int main(){

    vector<int> arr ={ 1,5,7,8,5,3,4,2,1} ;

    cout << longestSubsequence(arr ,-2) << endl;


}