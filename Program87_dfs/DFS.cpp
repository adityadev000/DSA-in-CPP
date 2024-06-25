//p87 -> DFS
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void dfs(int node ,unordered_map<int , bool > &visit ,unordered_map<int ,list<int> >& adj_list , vector<int> &compo  ){


    //store ans . 
    compo.push_back(node) ;

    //mark visit. 
    visit[node] = 1; 

    // recursive call for all neighbours. 
    for(auto i : adj_list[node]){

        if(! visit[i]){

            dfs(i , visit , adj_list, compo) ;

        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    //prepare adj list.
    unordered_map<int ,list<int> > adj_list ;

    for(int i =0 ;i < edges.size() ;i++ ){

        int u = edges[i][0] ;
        int v = edges[i][1] ;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);


    }

    vector<vector<int>> ans ; 

    unordered_map<int , bool > visit ;

    for(int i =0 ;i< V ;i ++ ){
        

        if(! visit[i]) {
            vector<int> compo ;
            dfs(i , visit , adj_list, compo) ;
            ans.push_back(compo) ;
        }


    }

    return ans ; 

}

int main(){

    vector<vector<int>> e = {{0 ,2},{0, 1},{1 ,2},{3, 4}} ;
    vector<vector<int>> ans = depthFirstSearch(   5  ,   4  , e);


    for(int i = 0; i< ans.size() ; i++){
        for(int j = 0; j< ans[i].size() ; j++){
            cout << ans[i][j] <<" " ;
        }
        cout  << endl;
    }


}