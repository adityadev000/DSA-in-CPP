//p119 -> dp18->  russian dolls envelopes.
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

    static bool comp (vector<int>& a ,vector<int>& b  ){
        if(a[0] != b[0] ){
            return a[0] < b[0] ; 
        }
        else{
            return a[1] > b[1] ;
        }
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin() , envelopes.end() , comp) ;

        if(envelopes.size() == 0 ){
            return 0 ; 
        }
        vector<int> ans;
        ans.push_back(envelopes[0][1]);

        for(int i =1 ; i< envelopes.size() ; i++ ){

            if(envelopes[i][1] > ans.back() ){

                ans.push_back(envelopes[i][1]) ;
            }
            else{

                 int index = lower_bound(ans.begin(), ans.end(), envelopes[i][1]) - ans.begin();
                ans[index] = envelopes[i][1] ;
            }

        }

        return ans.size() ; 
    }


int main(){

    vector<vector<int>> envelopes = {{5,4},{6,4},{6,7},{2,3}} ; 

    cout << maxEnvelopes(envelopes)  <<endl ;



}