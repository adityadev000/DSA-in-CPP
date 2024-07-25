//p140 -> q9 ->job sequencing problem.
#include<iostream>
#include<bits/stdc++.h>

using namespace std;


struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

static bool cmp (Job a ,Job b ){
        return a.profit > b.profit ;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr +n ,cmp ); 
        
        int max_dead_line = INT_MIN ;
        for(int i =0 ;i< n; i++ ){
            
            max_dead_line = max(max_dead_line  , arr[i].dead) ;
        }
        
        vector<int> schd(max_dead_line +1 , -1 ) ;
        
        int count =0 ;
        int max_profit= 0; 
        
        for(int i =0 ;i< n; i++ ){
            
            int curr_profit = arr[i].profit ;
            int curr_id = arr[i].id ;
            int curr_dead =  arr[i].dead ;
            
            for(int k = curr_dead ; k>=1 ;k-- ){
                
                if(schd[k] == -1 ){
                    count ++ ;
                    max_profit += curr_profit ;
                    schd[k] = curr_id ;
                    break ;
                }
            }
        }
        vector<int> ans ;
        ans.push_back(count) ;
        ans.push_back(max_profit) ;
        
        return ans ;
    } 

int main() {

    int n = 4 ;
    Job arr[4] = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)};


    vector<int> res = JobScheduling(arr, n);

    cout << "Number of jobs done: " << res[0] << endl;
    cout << "Maximum profit: " << res[1] << endl;
}

