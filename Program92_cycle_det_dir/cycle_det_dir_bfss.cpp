//// p92 -> q ->  Detect Cycle In A Directed Graph by BFS

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.

    //create adj list 
    unordered_map <int , list<int> > adj ; 

    for(int i =0 ;i < edges.size()  ;i ++ ){

      int u = edges[i].first -1 ;
      int v = edges[i].second-1 ; 

      adj[u].push_back(v);

    }


    //mark indegree of all node. 
    vector<int> indegree(n) ;

    for(auto i : adj ){

        for(auto j : i.second ){

            indegree[j] ++ ;

        }

    }

    //push into q node having indegree 0 .
    queue <int> q ; 
    for(int i =0 ;i<  n ;i ++ ){

        if (indegree[i] ==0 ){

            q.push(i) ;
        }
    }
     
      int cnt =0 ; 
    //bfs
    while(! q.empty() ){

       int f = q.front() ; 

        q.pop() ;
        
       cnt ++ ;  // count node in topo sort 

       for(auto i : adj[f] ){ // traverse all neighbour 

            //update indegree 
            indegree[i] -- ;  
            
            //chk if ingree is 0 . push into q. 
            if(indegree[i] == 0 ){

                q.push(i) ;
                
            }
            
       }
    }

    // return ans.
    if(cnt == n ){

//valid topo sort acyclic.
      return 0 ; 

    }

//invalid topo sort cyclic. 
    return 1 ; 
    
}

int main(){

    vector<pair<int ,int> > a = { {1 ,2} ,{4 ,1} ,{2 ,4} ,{3 ,4} ,{5 ,2} ,{1 ,3}   } ;

    cout << detectCycleInDirectedGraph(6 , a) << endl;


}