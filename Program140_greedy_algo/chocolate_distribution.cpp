//p140 -> q5 -> Chocolate Distribution Problem.
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

long long findMinDiff(vector<long long> a, long long n, long long m){
    // Sort the array in ascending order
    sort(a.begin(), a.end());
    

    int i = 0;
    int j = m - 1;
    
    // Initialize the minimum difference as INT_MAX
    int mini = INT_MAX;
    
    // Iterate through the array until j reaches the end
    while(j < a.size()){
        // Calculate the difference between the elements at indices j and i
        int diff = a[j] - a[i];
        
        // Update the minimum difference if the current difference is smaller
        mini = min(mini, diff);
        
        // Move both pointers one step forward
        i++;
        j++;
    }
    
    // Return the minimum difference found
    return mini;
}

int main(){

    vector<long long> a = {3, 4, 1, 9, 56, 7, 9, 12};
    long long n = 8;
    long long m = 5;
    
    long long minDiff = findMinDiff(a, n, m);
    
    cout << "Minimum difference: " << minDiff << endl;
    
    return 0;
}