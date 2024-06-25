//p90 ->   Topological Sort using dfs algo 

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void topo_sort(int node ,vector<bool> &visited,
                 stack<int> & s , unordered_map <int , list<int> > &adj){

    //mark visited curr node.
    visited[node] = 1 ; 

    //traverse all neighbouring node of curr node.
    for(auto i : adj[node] ){

        if(! visited[i]){

            topo_sort( i , visited , s , adj ) ;

        }
    }

//when func call ends push it into stack while popping in reverse order it get a topo sort
// if u ---> v .   u print before v. 
    s.push(node) ; 


}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    
    //create adj list.
    unordered_map <int , list<int> > adj ; 

    for(int i =0 ;i < e  ;i ++ ){

      int u = edges[i][0] ;
      int v = edges[i][1] ; 

      adj[u].push_back(v);

    }

    vector<bool> visited(v) ; //vector visited to mark visit

    stack<int>  s ;  //stack s store node when func call ends.


    //traverse all node and call func if not visited.
    for (int i =0 ;i < v ; i ++ ){

        if(! visited[i] ){

            topo_sort( i , visited , s , adj ) ;

        }
    }

    vector<int> ans ; 


//one by one push elemnts from stack to ans vector 
    while(! s.empty() ){

        ans.push_back(s.top()) ;

        s.pop() ;

    }

    return ans  ;
    

}

int main(){

    vector<vector<int> > a = { {2 , 1} , {1 , 0} , {3 , 2} , {0 , 1} , {0 , 2  }  } ;
 
    vector<int> ans = topologicalSort(a ,4 , 5 ) ;

    for(int i = 0; i< ans.size() ; i++){
        
        cout << ans[i] << " " ;

    }cout  << endl;

}