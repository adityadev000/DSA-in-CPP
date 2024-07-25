//p113 -> dp12->  min cost for tickets. or ninja's trip.
#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int solve_rec(int n, vector<int>& days, vector<int>& cost, int index) {
    // Base case
    // Agar index n se bada ho gaya hai, to 0 return karo (koi din nahi bacha hai)
    if (index >= n) return 0;

    // Option 1: Din-by-din ticket lene ka cost aur aage ke din ke liye recursion call karo
    int opt1 = cost[0] + solve_rec(n, days, cost, index + 1);

    // Option 2: 7 din ka ticket lene ka cost aur 7 din ke baad ke din tak recursion call karo
    int i;
    for (i = index; i < n && days[i] < days[index] + 7; i++);  // 7 din tak ke din count karo
    int opt2 = cost[1] + solve_rec(n, days, cost, i);

    // Option 3: 30 din ka ticket lene ka cost aur 30 din ke baad ke din tak recursion call karo
    for (i = index; i < n && days[i] < days[index] + 30; i++);  // 30 din tak ke din count karo
    int opt3 = cost[2] + solve_rec(n, days, cost, i);

    // Teeno options me se minimum cost return karo
    return min(opt1, min(opt2, opt3));
}


int solve_rec_memo(int n, vector<int> &days, vector<int>& cost ,int index,vector<int> &dp ){

    if(index >= n ) return 0 ;
    if(dp[index] != -1 ) return dp[index] ;

    int opt1 = cost[0] + solve_rec_memo(n, days ,cost ,index+1 , dp  ) ;


    int i ;
    for(i = index ; i< n && days[i] < days[index] + 7 ; i++  ) ;
    int opt2 = cost[1] +solve_rec_memo(n ,days ,cost, i , dp ) ;


    for(i = index ; i< n && days[i] < days[index] + 30 ; i++  ) ;
    int opt3 = cost[2] +solve_rec_memo(n ,days ,cost ,i , dp ) ;


    dp[index] =  min(opt1 , min(opt2 ,opt3 )) ;
    return dp[index] ; 


}


int solve_tabulisation(int n, vector<int> &days, vector<int>& cost ){

    vector<int> dp(n+1 ,INT_MAX ) ;
    dp[n] = 0 ; 

    for(int k = n-1 ; k>=0 ; k-- ){

        int opt1 = cost[0] + dp[k+1] ;


        int i ;
        for(i = k ; i< n && days[i] < days[k] + 7 ; i++  ) ;
        int opt2 = cost[1] +dp[i]  ;


        for(i = k ; i< n && days[i] < days[k] + 30 ; i++  ) ;
        int opt3 = cost[2] +dp[i]  ;

        dp[k] = min(opt1 , min(opt2 ,opt3 )) ;
    }

    return dp[0] ; 

}



int minimumCoins(int n, vector<int> days, vector<int> cost)
{   

    // return solve_rec(n , days ,cost , 0 ) ;

    // vector<int> dp(n ,-1 ) ;
    // return solve_rec_memo(n , days ,cost , 0 , dp ) ;

    return solve_tabulisation(n , days ,cost ) ;

    // return solve_opt(n , days ,cost);
}


int main(){

    vector<int> days = {1 ,3, 4 ,5,7 ,8 ,10} ;
    vector<int> cost = {2 ,7 ,20} ; 

    cout << minimumCoins (7 , days , cost ) << endl;


}