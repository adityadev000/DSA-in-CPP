
#include<iostream>
#include<bits/stdc++.h>

using namespace std;


vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Write your code here
	//create adj list 
    unordered_map <int , list<int> > adj ; 

    for(int i =0 ;i < edges.size()  ;i ++ ){

      int u = edges[i].first ;
      int v = edges[i].second ; 

      adj[u].push_back(v);
      adj[v].push_back(u);

    }

	//bfs 
	unordered_map<int , bool > visited(n) ;

	unordered_map<int ,int> parent(n)  ;

	queue< int> q ;

	q.push(s) ; 

	visited[s] =1 ; 

	parent [s] = -1 ; 

	while (! q.empty() ){

		int f=  q.front() ;
		q.pop() ;

		for(auto i : adj[f] ){

			if(! visited[i] ){

				visited[i]  = 1 ; 

				parent[i] = f ;

				q.push(i) ;

			}
		}
	}

	//prepare shortest path.

	vector<int> ans ;

	int curr = t ;

	ans.push_back(t) ;

	while( curr != s ){

		curr = parent[curr] ;

		ans.push_back(curr) ;

	}

	reverse(ans.begin() , ans.end()) ;

	return ans ; 
	
}

int main(){

    vector<pair<int ,int> > a = {  {1 ,2} ,{1 ,3} ,{1 ,4} ,{2 ,5} ,{5 ,8 } ,{3 ,8} ,{4 ,6} ,{6 ,7} ,{7, 8 }   } ;

    vector<int> ans  = shortestPath(a , 8 , 9 , 1, 8 ) ;

    for ( auto i : ans ){
    
        cout << i << " " ;
    
    }cout  << endl;

}