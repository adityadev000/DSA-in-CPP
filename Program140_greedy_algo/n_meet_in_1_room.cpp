// p140 -> q1 -> N meeting in one room.
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

static bool cmp(pair<int ,int> a , pair<int ,int> b ){
        
        return a.second < b.second ;
    }

    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int ,int > > v ;
        
        for(int i =0 ;i < n ;i ++ ){
            
            v.push_back({start[i] , end[i] }) ;
            
        }
        
        sort(v.begin() , v.end() , cmp ) ;
        
        int count =0 ; 
        int e_t = 0  ;
        
        for(int i =0 ;i< n ;i ++ ){
            
            if(v[i].first > e_t ){
                
                count ++ ;
                
                e_t = v[i].second ;
            }
        }
        
        return count ;
        
    }


int main(){

    int n = 6 ; 
    int s[n] = {1,3,0,5,8,5} ;
    int e [n] = {2,4,6,7,9,9} ;

    cout << maxMeetings(s , e ,n ) << endl;


}