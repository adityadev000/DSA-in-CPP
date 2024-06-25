//p96 -> Minimum Spanning Tree kruskals algo.
#include<iostream>
#include<bits/stdc++.h>

using namespace std;


// Compare krne wala function weight ke hisaab se sort krne ke liye
bool cmp(vector<int> &a, vector<int> &b) {
  // Agar edge 'a' ka weight 'b' se kam hai toh true return karega
  return a[2] < b[2];
}

// Given node ka parent find krne wala function
int find_parent(vector<int> &parent, int node) {
  // Agar node apna hi parent hai toh node return krdega
  if (parent[node] == node) {

    return node;

  }

  // Recursively parent find krke path compression bhi karega
  return parent[node] = find_parent(parent, parent[node]);
}

// Do sets ko union krne wala function
void union_set(int u, int v, vector<int> &parent, vector<int> &rank) {
  // Dono nodes ke parents find kr le

  u = find_parent(parent, u);

  v = find_parent(parent, v);

  // Rank ke hisaab se union kr: chhoti tree ko badi tree ke root ke neeche daal de
  if (rank[u] < rank[v]) {

    parent[u] = v;

  }
  
   else if (rank[v] < rank[u]) {

    parent[v] = u;

  } 
  else {
    // Agar rank same hai toh kisi ek ko root bnaake uski rank badha de

    parent[u] = v;
    rank[v]++;

  }

}

// Kruskal's algorithm use krke minimum spanning tree find krne wala function

int minimumSpanningTree(vector<vector<int>> &edges, int n) {
  // Sabhi edges ko unke weight ke hisaab se sort krde
  sort(edges.begin(), edges.end(), cmp);

  // Parent aur rank vectors initialize kr le disjoint set ke liye
  vector<int> parent(n);
  vector<int> rank(n, 0);

  // Shuruaat mein, har node ko apna parent bna de
  for (int i = 0; i < n; i++) {

    parent[i] = i;
    
  }

  int ans = 0; // Minimum spanning tree ka total weight store krne wala variable

  // Sabhi edges pe iterate kr

  for (int i = 0; i < edges.size(); i++) {

    // Current edge ke endpoints ke parents find krle
    int u = find_parent(parent, edges[i][0]);
    int v = find_parent(parent, edges[i][1]);
    int wt = edges[i][2];

    // Agar parents alag hain toh edge cycle nhi banata
    if (u != v) {

      // Sets containing u aur v ko union kr
      union_set(u, v, parent, rank);

      // Edge ka weight minimum spanning tree ke total weight mein add krde
      ans += wt;

    }
  }

  // Minimum spanning tree ka total weight return krde
  return ans;

}


int main(){

    
    int n = 4, m = 4;

    vector<vector<int>> edges = {
        {0, 1, 3},
        {0, 3, 5},
        {1, 2, 1},
        {2, 3, 8}
    };


    cout <<  minimumSpanningTree(edges, n) << endl; 

    


}