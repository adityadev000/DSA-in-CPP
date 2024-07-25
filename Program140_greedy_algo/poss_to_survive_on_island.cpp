//p140 -> q3 -> Check if it is possible to survive on Island.

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int minimumDays(int S, int N, int M){
        
        // if( M > N ) return -1 ;
        
        int sunday = S / 7 ; 
        
        int buy_day = S - sunday ; 
        
        int total  = (S* M) ;
        
        int ans =0;
        
        if(total % N == 0 ) 
            ans = total  /N  ;
        
        else 
            ans = total /N +1 ;
        
        
    
        if(ans <= buy_day)
            return ans ;
            
        else return -1 ;
        
    }


int main(){

    cout << minimumDays(10 ,9 ,8 ) << endl;


}