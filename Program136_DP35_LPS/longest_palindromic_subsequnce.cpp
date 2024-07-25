//p136 -> dp35-> longest palindromic subsequence.
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int solve_space_opt(string text1, string text2 ){

        //bc
        int n = text1.length() ;
        int m = text2.length() ;

        vector<int> curr(m+1 , 0 );
        vector<int> next(m+1 , 0 );

        for(int i = n-1 ; i>=0 ;i-- ){

            for(int j = m-1 ;j>=0 ;j -- ){

                if(text1[i] == text2[j] ) {
                    curr[j] =  1+ next[j+1] ;
                }

                else{
                    curr[j] =  max( next[j] , curr[j+1] ) ;
                }

            }
            next = curr ;
        }

        return next[0] ;
    }
    int longestPalindromeSubseq(string s) {
        string r = s ;
        reverse(s.begin() ,s.end()) ;

        return solve_space_opt(s ,r ); 
    }


int main(){

    string s = "bbbab" ;
    cout << longestPalindromeSubseq(s) << endl;


}