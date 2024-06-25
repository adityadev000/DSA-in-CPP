//p98 ->  Bridges In A Graph.
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// DFS function to find bridges
void dfs(int node ,int parent ,int &timer ,vector<int> &disc,vector<int> &low,vector<vector<int>> &result,
vector<bool> &visited, unordered_map<int, list<int> > &adj){

    // Abhi ke node ko visited mark kar do
    visited[node] = 1;

    // Discovery aur low value set kar lo
    disc[node] = low[node] = timer++;

    // Current node ke saare neighbors ke liye loop
    for(auto nbr : adj[node]){

        // Agar neighbor parent hai, to continue kar do
        if(nbr == parent) continue;

        // Agar neighbor visited nahi hai, to us par recursion lagao
        if(!visited[nbr]){

            dfs(nbr, node, timer, disc, low, result, visited, adj);

            // Check karo ki subtree rooted at nbr ke pass connection hai ya nahi ancestors of node ke saath
            low[node] = min(low[node], low[nbr]);

            // Agar lowest vertex reachable from subtree under nbr is below discovery time of node
            if(low[nbr] > disc[node]){
                vector<int> ans;

                // Node aur nbr ko result me add karo
                ans.push_back(node);
                ans.push_back(nbr);

                result.push_back(ans);
            }
            
        } else {
            // Parent function calls ke liye low value update karo
            low[node] = min(low[node], disc[nbr]);
        }
    }
}

// Function to find bridges in the graph
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {

    // Adjacency list banao
    unordered_map<int, list<int> > adj;

    // Saari edges ke liye loop
    for(int i = 0; i < e; i++){

        int u = edges[i][0];
        int v = edges[i][1];

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

    // Bridges store karne ke liye result array
    vector<vector<int>> result;

    // Saare nodes ke liye loop
    for(int i = 0; i < v; i++){

        // Agar node visited nahi hai to dfs call karo
        if(!visited[i]){
            dfs(i, parent, timer, disc, low, result, visited, adj);
        }
    }

    return result;
}

int main() {
    int v = 5, e = 4; // Number of vertices and edges
    vector<vector<int>> edges = {{0, 1}, {3, 1}, {1, 2}, {3, 4}, {3, 3}, {0, 1}}; // Given edges

    // Finding the bridges
    vector<vector<int>> bridges = findBridges(edges, v, e);

    // Print the bridges
    cout << "Bridges hain: " << endl;
    for (auto bridge : bridges) {
        cout << bridge[0] << " - " << bridge[1] << endl;
    }


}
