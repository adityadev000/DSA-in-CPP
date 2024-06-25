// p89 -> q ->  Detect Cycle In A Directed Graph by DFS
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int is_cycle_dfs(int node , unordered_map<int ,bool > &visited ,unordered_map<int ,bool >& dfs_visited,
unordered_map <int , list<int> > &adj){

visited[node] = 1 ;

  dfs_visited[node] = 1 ;

  for(auto i : adj[node] ){

	if(!visited[i]){

      	int cycle = is_cycle_dfs(i , visited , dfs_visited , adj) ;

      	if(cycle) return 1 ;

    }
    else if( dfs_visited[i]){

      	return 1 ; 

    }

  }

  dfs_visited[node] = 0 ;

  return 0 ;


}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.


  unordered_map <int , list<int> > adj ; 

    for(int i =0 ;i <edges.size() ;i ++ ){

      int u = edges[i].first ;
      int v = edges[i].second ; 

      adj[u].push_back(v);

    }

  unordered_map<int ,bool > visited ;
  unordered_map<int ,bool > dfs_visited ;


    for(int i =0 ;i <n ; i++  ){

      if(!visited[i] ){

        int ans = is_cycle_dfs(i , visited , dfs_visited , adj) ;

        if(ans) return 1; 

      }

    }
  
    return 0 ;

}

int main(){

    vector<pair<int ,int> > a = { {1 ,2} ,{4 ,1} ,{2 ,4} ,{3 ,4} ,{5 ,2} ,{1 ,3}   } ;

    cout << detectCycleInDirectedGraph(6 , a) << endl;

  

}