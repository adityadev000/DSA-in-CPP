//p101 ->  Bellman Ford for shortest path if(-ve wt is given in directed graph ).
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
   // Sab nodes ke liye initial distance infinity set karo
    vector<int> dist(n+1 , 1e8); 

    // Source ka distance 0 set karo
    dist[src] = 0; 

    // Loop for (n-1) times to  all edges
    for(int i = 1; i < n; i++) { 

        // Traverse through all edges
        for(int j = 0; j < m; j++) { 

            // Extracting edges details: start, end, and weight
            int u = edges[j][0]; 
            int v = edges[j][1]; 
            int w = edges[j][2]; // Edge ka weight

            // If the current distance to u plus weight is less than distance to v, update it
            if(dist[u] + w < dist[v]) { // Agar current distance + weight, v ka distance se chhota hai
                dist[v] = dist[u] + w; // To v ka distance update karo
            }
        }
    }

    // Loop again through all edges to check for negative weight cycles
    for(int j = 0; j < m; j++) { // Dobara sab edges check karo negative weight cycle detect karne ke liye

        int u = edges[j][0]; 
        int v = edges[j][1]; 
        int w = edges[j][2]; 

    
        if(dist[u] + w < dist[v]) { 
            return {-1};
        }
    }

    // Return the distance array
    return dist; 
}



int main() {

    int n = 4, m = 3, src = 1;
    vector<vector<int>> edges = {{1, 2, 4}, {1, 3, 3}, {2, 4, 7}, {3, 4, -2}};

    vector<int> dist = bellmonFord(n, m, src, edges);

    for(int i = 1; i <= n; i++) {
        cout << "Distance from " << src << " to " << i << " is " << dist[i] << endl;
    }

}