// p140 -> q4 ->Reverse words.
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

string reverseWords(string S) 
    { 
        string ans = "" ;
        
        int i = S.length() -1 ;
        
        
        
        while(i >= 0 ){
            
            int count =0; 
            
            while(S[i] != '.'  && i>=0 ){
                
                i -- ;
                count ++ ;
            } 
        
            
            ans +=  S.substr(i+1 , count ) ;
            
            if(i > 0 )
            // ans.push_back('.') ;
            ans+= '.' ;
            
            i-- ;
        }
        return ans ;
    } 


int main(){

    string s = "i.like.this.program.very.much" ;
    cout << reverseWords(s) << endl;


}