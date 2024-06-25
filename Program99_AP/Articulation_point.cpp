// P99 -> find articulation point.

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// DFS function to find articulation points
void dfs(int node ,int parent ,int &timer ,vector<int> &disc,vector<int> &low,vector<int> &ap,
vector<bool> &visited, unordered_map<int, list<int> > &adj){

    // Abhi ke node ko visited mark kar do
    visited[node] = 1;

    // Discovery aur low value set kar lo
    disc[node] = low[node] = timer++;

    int child = 0; // Child nodes count karne ke liye

    // Current node ke saare neighbors ke liye loop
    for(auto nbr : adj[node]){

        // Agar neighbor parent hai, to continue kar do
        if(nbr == parent) continue;

        // Agar neighbor visited nahi hai, to us par recursion lagao
        if(!visited[nbr]){

            dfs(nbr , node ,timer ,disc ,low ,ap , visited , adj);

            // Check karo ki subtree rooted at nbr ke pass connection hai ya nahi ancestors of node ke saath
            low[node] = min(low[node] ,low[nbr]);

            // Agar lowest vertex reachable from subtree under nbr is below discovery time of node
            if(low[nbr] > disc[node] && parent != -1){
                ap[node] = 1; // node ek articulation point hai
            }
            child++;

        } else {
            // Parent function calls ke liye low value update karo
            low[node] = min(low[node] ,disc[nbr]);
        }
    }

    // Agar node root hai DFS tree ka aur uske 2 ya usse zyada children hai
    if(parent == -1 && child > 1){

        ap[node] = 1;

    }
}

int main(){
    int v = 5, e = 5;

    // Edges ki list
    vector<pair<int,int>> edges;

    // Edges ko list me add karo
    edges.push_back({0,3});
    edges.push_back({3,4});
    edges.push_back({0,4});
    edges.push_back({0,1});
    edges.push_back({1,2});

    // Adjacency list banao
    unordered_map<int, list<int> > adj;

    // Saari edges ke liye loop
    for(int i = 0; i < e; i++){

        int u = edges[i].first;
        int v = edges[i].second;

        // Graph me add karo
        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    int timer = 0;

    // Initialize discovery aur low arrays
    vector<int> disc(v, -1);
    vector<int> low(v, -1);

    int parent = -1;

    // Visited array banao
    vector<bool> visited(v, false);

    // Articulation point array
    vector<int> ap(v, 0);

    // Saare nodes ke liye loop
    for(int i = 0; i < v; i++){

        // Agar node visited nahi hai to dfs call karo
        if(!visited[i]){
            dfs(i, parent, timer, disc, low, ap, visited, adj);
        }
    }

    // Articulation points print karo
    cout << "articulation point hai : " << endl;

    for(int i = 0; i < v; i++){
        if(ap[i] != 0){
            cout << i << endl;
        }
    }

}
