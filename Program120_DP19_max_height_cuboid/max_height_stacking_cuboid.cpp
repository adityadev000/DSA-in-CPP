//p120 -> dp19->  max height of cuboid

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// Function to check if 'new_box' can be placed on top of 'base'
bool check(vector<int> base , vector<int> new_box){

    // Check if all dimensions of base are greater than or equal to new_box
    if((base[0] >= new_box[0]) && (base[1] >= new_box[1]) &&(base[2] >= new_box[2] )) {

        return true ;

    }
    return false ;
}

// Function to solve the problem using DP
int solve (int n, vector<vector<int>>& a){
     
    vector<int> curr_r(n+1 , 0 );
    vector<int> next_r(n+1 , 0 );

    // Looping from the end to start
    for(int curr = n-1 ;curr >= 0 ; curr --  ){

        for(int prev = curr -1 ; prev >= -1 ; prev -- ){

            int incl =0 ;

            // If prev is -1 or we can place curr on prev
            if(prev == -1 || check(a[curr] , a[prev]) ){

                incl = a[curr][2] + next_r[curr+1] ;

            }

            int excl = 0 + next_r[prev+1] ;

            // Storing the max value in curr_r
            curr_r[prev+1] = max(incl , excl ) ;
        }

        // Moving to the next row
        next_r = curr_r ;
    }

    // Return the max height possible
    return next_r[0] ; 
}

// Function to find the max height of stacked cuboids
int maxHeight(vector<vector<int>>& cuboids) {
    
    // Sorting each cuboid's dimensions
    for(int i =0 ;i < cuboids.size() ; i++ ){

        sort(cuboids[i].begin() , cuboids[i].end()) ;
        
    }

    // Sorting all cuboids
    sort(cuboids.begin() , cuboids.end()) ;

    // Solving the problem with sorted cuboids
    return solve(cuboids.size() , cuboids) ;
}

int main() {
    
    vector<vector<int>> cuboids = {{50,45,20},{95,37,53},{45,23,12}};

    // Calling the function and printing the result
    cout << "The maximum height of stacked cuboids is: " << maxHeight(cuboids) << endl;

}