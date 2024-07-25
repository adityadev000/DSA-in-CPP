//p114 -> dp13->  min cost for tickets space optimised.
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int solve_opt(int n, vector<int> days, vector<int> cost) {
    int ans =0 ;

    queue<pair<int ,int>> month ;
    queue<pair<int ,int>> week ;

    for(auto day :days ){

        //remove expire days 
        while(!month.empty() && month.front().first +30 <= day)
            month.pop() ;

        while(!week.empty() && week.front().first +7 <= day)
            week.pop() ;

        //add
        week.push({day , ans+ cost[1] });
        month.push({day , ans+ cost[2] });

        ans = min(ans + cost[0] , min(week.front().second ,month.front().second )) ;
    }
    return ans ; 
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{   


    return solve_opt(n , days ,cost);
}



int main(){

    vector<int> days = {1 ,3, 4 ,5,7 ,8 ,10} ;
    vector<int> cost = {2 ,7 ,20} ; 

    cout << minimumCoins (7 , days , cost ) << endl;


}