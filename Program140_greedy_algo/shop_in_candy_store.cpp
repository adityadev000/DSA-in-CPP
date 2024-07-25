// p140 -> q2 -> Shop in Candy Store.
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

 vector<int> candyStore(int candies[], int N, int K)
    {
        vector<int> ans(2 ,0 ) ;
        
        int c = N / (K+1) ;
        
        if(N % (K+1) != 0 ){
            c ++ ; 
        }
        
        sort(candies , candies + N  ) ;
        

        for(int i =0 ;i < c ;i ++  ){
            
            ans[0] += candies[i] ;
            
            ans[1] += candies[N-i - 1] ;
            
        }
        
        return ans ;
    }


int main(){
    int n = 4 ;
    int candies[n] = {3 ,2 ,1, 4} ;

    vector<int> ans = candyStore(candies , n ,2 );
    
    cout << ans[0] << endl << ans[1] << endl;



}