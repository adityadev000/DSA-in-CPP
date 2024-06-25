//p94 -> Shortest path in a weighted directed acyclic graph

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Graph{

public :

    //create adj_list. 
	unordered_map<int ,list<pair <int,int> > > adj ;

	void add_edge(int u ,int v , int weight ){

		pair<int ,int> p = {v , weight} ;

		adj[u].push_back(p) ;

	}

	void print_adj(){

		for ( auto i : adj ){

			cout << i.first << " -> " ;

			for ( auto j : i.second  ){
			
				cout <<  "( " << j.first << " , " << j.second <<  " )" ;

			} cout  << endl;
		
		}

	}

    // store topo sot in stack by dfs.
	void topo_sort_dfs(int node ,unordered_map<int ,bool > &visited , stack<int> & s) {

		visited[node] = 1 ;

		for ( auto i : adj[node] ){
			
			if(! visited[i.first] ){

				topo_sort_dfs(i.first ,  visited , s) ;

			}
		
		
		}

        //func call wapas atte hue node ko stack me daal do.
		s.push(node) ;

	}

	void get_shortest_path(int src ,vector<int> &  dist , stack<int>  s ){

		dist[src] = 0 ; //make src dist = 0; 

		while (! s.empty() )
		{
			int top = s.top() ;

			s.pop() ;


        //if dist != infinity the need of processing and update. 
			if(dist[top] != INT32_MAX ){

                //traverse all neighbour.
				for ( auto i : adj[top] ){
					
                    // new dist is lesser than old update.
					if(dist[top] + i.second < dist[i.first]){

						dist[i.first] = dist[top] + i.second ;

					}
			
				}
			}

		}
		
	}


};


int main(){

	Graph g ; //creating obj.


    //adding edges.
	g.add_edge(0,1,5) ;
	g.add_edge(0,2,3) ;
	g.add_edge(1,2,2) ;
	g.add_edge(1,3,6) ;
	g.add_edge(2,3,7) ;
	g.add_edge(2,4,4) ;
	g.add_edge(2,5,2) ;
	g.add_edge(3,4,-1) ;
	g.add_edge(4,5,-2) ;

	g.print_adj() ;

	int n = 6 ;

	unordered_map<int ,bool > visited(n) ;

	stack<int> s ;

    //store topo sort in stack.
	for(int i =0 ;i < n ;i ++ ){

		if(! visited[i] ){

			g.topo_sort_dfs(i,  visited ,s ) ;
		}

	}

	int src = 1 ;  //mark ource here.

	vector<int> dist(n) ; //creating dist array and initilised with infinty.

	for(int i =0; i<n ;i ++ ){

		dist[i] = INT32_MAX ;

	}

    //get shortest path
	g.get_shortest_path(src , dist ,s ) ;


    //printing ans. 
	cout << "Answer is " << endl;

	for ( auto i : dist ){
		
		cout <<  i << " " ;

	} cout  << endl;



}