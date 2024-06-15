//p85 -> graph adj list -> vector .

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    // Write your code here.
    vector<int> ans [n] ;//2d matrix

    for(int i =0 ;i < m ;i ++ ){

        int u = edges [i][0] ;
        int v = edges [i][1] ;

        ans[u].push_back(v) ;
        ans[v].push_back(u) ;
    }
        vector<vector<int>> list(n) ;

        for(int i =0 ;i< n; i++ ){

            list[i].push_back(i) ;

            for(int j = 0 ; j < ans[i].size() ; j++){
                list[i].push_back(ans[i][j]);
            }
    }

    return list ;
}

int main(){

vector < vector < int >> e =  
{{1, 2},
{0 ,3}
,{2 ,3}} ;

        vector < vector < int >> ans = printAdjacency(4,3,e) ;

        for(int i = 0; i< ans.size() ; i++){

            for(int j = 0; j< ans[i].size() ; j++){
                cout << ans[i][j] << " ";
            }
            cout  << endl;
            
        }

}