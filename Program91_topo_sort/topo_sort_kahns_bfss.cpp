//p91 ->   Topological Sort using kahn's algo or bfs 

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {

    //create adj list 
    unordered_map <int , list<int> > adj ; 

    for(int i =0 ;i < e  ;i ++ ){

      int u = edges[i][0] ;
      int v = edges[i][1] ; 

      adj[u].push_back(v);

    }


    //mark indegree of all node. 
    vector<int> indegree(v) ;

    for(auto i : adj ){

        for(auto j : i.second ){

            indegree[j] ++ ;

        }

    }

    //push into q node having indegree 0 .
    queue <int> q ; 
    for(int i =0 ;i< v ;i ++ ){

        if (indegree[i] ==0 ){

            q.push(i) ;
        }
    }
     
    vector<int> ans ; 
    //bfs
    while(! q.empty() ){

       int f = q.front() ; 

        q.pop() ;
        
       ans.push_back(f) ; // push in ans whoose indegree is zero.

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
    return ans  ;
    

}

int main(){

    vector<vector<int> > a = { {2 , 1} , {1 , 0} , {3 , 2} , {0 , 1} , {0 , 2  }  } ;
 
    vector<int> ans = topologicalSort(a ,4 , 5 ) ;

    for(int i = 0; i< ans.size() ; i++){
        
        cout << ans[i] << " " ;

    }cout  << endl;

    cout << "size= " << ans.size() << endl;
    cout << ans[3] << endl;

}