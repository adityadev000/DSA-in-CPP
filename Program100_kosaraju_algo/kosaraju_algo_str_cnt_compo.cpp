//p100 -> Count Strongly Connected Components (Kosaraju’s Algorithm).
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void dfs(int node , unordered_map<int , bool> &visited , stack<int> &s ,unordered_map<int ,list<int> > & adj ){
    // Yeh node visit ho gaya
    visited[node] = 1 ;

    // Sab neighbors ko visit karo
    for(auto nbr : adj[node]){

        if(!visited[nbr]) {

            dfs(nbr , visited ,s , adj ) ;

        }
    }
    // Topological sort ke liye node ko stack mein daalo
    s.push(node) ;
}

void rev_dfs(int node , unordered_map<int , bool> &visited , unordered_map<int ,list<int> > & transpose ){
    // Yeh node visit ho gaya
    visited[node] = 1 ;

    // Sab neighbors ko visit karo
    for(auto nbr : transpose[node]){

        if(!visited[nbr]) {

            rev_dfs(nbr , visited ,transpose ) ;
        }
    }
}


int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    // Yeh code likhna hai
    unordered_map<int ,list<int >> adj ;

    // Graph ka adjacency list banao
    for(int i =0 ;i < edges.size() ;i++ ){

        int u = edges[i][0];

        int v = edges[i][1] ;

        adj[u].push_back(v) ;

    }

    // Topological sort ke liye stack aur visited map
    stack<int> s ;
    unordered_map<int , bool> visited ;

    // Har ek vertex ke liye DFS call karo
    for(int i =0 ;i< v ;i ++ ){

        if(!visited[i] ){

            dfs(i , visited ,s , adj ) ;

        }
    }

    // Transpose graph banao
    unordered_map<int ,list<int >> transpose ;

    for(int i =0 ; i< v ;i ++ ){

        visited[i] = 0 ;

        for(auto nbr : adj[i] ){

            transpose[nbr].push_back(i) ;
        }
    }

    // Strongly connected components count karo
    int count = 0; 

    while(! s.empty()) {

        int top = s.top() ;
        s.pop() ;

        if(!visited[top] ){

            count ++ ;

            rev_dfs(top , visited ,transpose) ;

        }
    }

    return count ;
}



int main(){

    // Number of vertices
    int v = 5;

    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {1, 4},
        {2, 3},
        {3, 2},
        {4, 0}
    };

    int result = stronglyConnectedComponents(v, edges);
    cout << "Number of strongly connected components: " << result << endl;


}