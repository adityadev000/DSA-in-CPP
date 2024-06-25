// p88 -> q ->  Detect Cycle In A UnDirected Graph
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool is_cyclic_bfs(int src ,unordered_map<int ,bool > &visited ,unordered_map <int , list<int> > &adj  ){

    unordered_map<int , int > parent ;

    parent[src] = -1 ;

    visited[src] = 1 ;

    queue<int> q ;
    q.push(src) ;

    while(!q.empty() ){
        int f= q.front() ;
        q.pop() ;

        for(auto i  : adj[f]) {

            if( visited[i]  && parent[f] != i ){

                return true ;

            }
            else if (!visited[i]) {
                q.push(i); 
                visited[i] =1 ;
                parent[i] = f ; 
            }

        }
    }
    
    return false ;

}

bool is_cyclic_dfs(int src , int parent ,unordered_map<int ,bool > &visited ,unordered_map <int , list<int> > &adj ){

    visited[src] =1 ;

    for(auto i : adj[src]){
        if(!visited[i]) {

            bool cycle = is_cyclic_dfs(i , src , visited,adj) ;

            if(cycle) return true ;
        }

        else if (i != parent ) {
            return true ;
        }
    }
    return false ;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    unordered_map <int , list<int> > adj ; 

    for(int i =0 ;i <m ;i ++ ){

        int u = edges[i][0] ;
        int v = edges[i][1] ;

        adj[u].push_back(v);
        adj[v].push_back(u);


    }

    unordered_map<int ,bool > visited ;

    for(int i =1 ; i <= n ;i++  ){
        if(!visited[i]) {

            bool ans  = is_cyclic_dfs(i ,-1,  visited ,adj) ;
            // bool ans  = is_cyclic_bfs(i ,  visited ,adj) ;

            if(ans) return "Yes" ;
        }
    }

    return "No" ;

}


int main(){

    vector<vector<int> > a = { {1 ,2} ,{4 ,1} ,{2 ,4} ,{3 ,4} ,{5 ,2} ,{1 ,3}   } ;

    cout << cycleDetection(a , 5, 6 ) << endl;

}
