#include<iostream>
#include<bits/stdc++.h>

using namespace std;

long long int solve(vector<long long int>& nums   ){

    long long int prev2 = 0 ;
    long long int prev1 = nums[0] ;

    for(int i =1 ;i < nums.size(); i++ ){

        long long int incl = prev2 + nums[i] ;

        long long int excl = prev1 +0 ;
        
        long long int ans = max(incl , excl );

        prev2 = prev1 ;

        prev1 = ans  ;
    }

    // final answer return karo
    return prev1 ;
}
long long int houseRobber(vector<int>& valueInHouse)
{

    int n = valueInHouse.size() ;

    if(valueInHouse.size() == 1 ){

        return valueInHouse[0] ;

    }
    vector<long long int> first ,second ;
    

    for(int i =0; i< n ; i++ ){

        if(i!= 0 ){

            first.push_back(valueInHouse[i]) ;

        }


        if(i!= n-1){

            second.push_back(valueInHouse[i]) ;

        }
        
    }

    return max(solve(first) , solve(second)) ;
}


int main(){




}