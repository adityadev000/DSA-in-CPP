//p95 ->  Dijkstra's shortest path
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {

    //create adj list 
    unordered_map<int , list < pair <int, int > > > adj ;
    for(int i =0 ;i< edges ;i ++ ){

        int u  = vec[i][0];
        int v  = vec[i][1];
        int w  = vec[i][2];

        adj[u].push_back(make_pair(v,w)) ;
        adj[v].push_back(make_pair(u,w)) ;

    }

//make dist array initialised with int max.
    vector<int> dist (vertices) ;
    for(int i = 0 ;i < vertices ;i ++ ){

        dist[ i] = INT_MAX ;

    }

    set<pair<int , int> > st ;

    dist[source] =0 ; //dist of source  =0 ; 

    st.insert(make_pair(0 , source)) ; //insert in set 0 dist for source

    while(! st.empty() ){

        auto  top = *(st.begin()) ; //find top element

        int node_dist = top.first ; //set node dist 

        int top_node = top.second ;//set top_node -> data.

        st.erase(st.begin()) ; //pop it 

    //traverse all neighbour of top_node.
        for(auto i : adj[top_node]){ 

            // if node dist is lesser than prev dist update it and update the new entry of top node in set with updated dist.
            if(node_dist + i.second < dist[i.first]){

                auto record  = st.find(make_pair( dist[i.first] , i.first ) );

                if(record != st.end()) {

                    st.erase(record) ;
                }

                dist[i.first] = node_dist + i.second ;

                st.insert(make_pair(dist[i.first] , i.first )) ;
            }
        }
    }

    return dist ;
}


int main(){


    vector<vector<int>> v = {{0, 1, 5},{0, 2, 8},{1, 2, 9},{1, 3, 2},{2, 3, 6}} ;

    vector<int> ans = dijkstra(v , 4 ,5 , 0 ) ;

    for ( auto i : ans ){
    
        cout <<i << " ";
    
    
    }cout  << endl;

}