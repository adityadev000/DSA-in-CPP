//p85 --> graph implementation by adjancency list.


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class graph {
    public :

        map<int , list<int>>  adj ; 

        void add_edge (int u , int  v , bool direction){

            // directed  -> 1 :  undirected ->0

            adj[u].push_back(v) ;


            //if undirected make v ---> u link also.
            if(direction == 0 ){

                adj[v].push_back(u) ;

            }

        }

        void print_list(){

            for(auto i : adj ){

                cout << i.first << " -> " ;

                for(auto j : i.second){

                    cout << j << " " ;
                }

                cout  << endl;

            }
        }
};

int main(){

    int n , m ;

    cout << "enter no. of nodes " << endl;
    cin >> n ; 

    cout << "enter no. of edges " << endl;
    cin >> m ; 

    graph g ; 

    for(int i =0 ; i< m ; i++ ){

        int u ,v ;
        cin >> u >>  v ;

        g.add_edge(u , v , 1) ;
        
    }

    g.print_list() ;
}