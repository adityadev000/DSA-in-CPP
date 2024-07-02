//p96 ->  Prim's MST
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{

    //create adj_list
   unordered_map<int , list < pair <int, int > > > adj ;

    for(int i =0 ;i < g.size() ; i++ ){

        int u = g[i].first.first ;
        int v = g[i].first.second ;
        int w = g[i].second ;

        adj[u].push_back(make_pair(v,w)) ;
        adj[v].push_back(make_pair(u,w)) ;

    }

    // crete ds nedded 
    vector<int> key(n+1) ;
    vector<bool> mst (n+1) ;
    vector<int> parent(n+1) ;

    for(int i= 1 ;i <= n ;i++ ){

        key[i] = INT_MAX ;
        mst[i] = false ;
        parent[i] = -1 ;

    } 

    key[1] = 0 ; parent[1] = -1 ;


    // traverse all nodes.
    for(int i =1 ;i<= n ;i ++ ){

        int mini = INT_MAX ;

        int u  = -1 ;


    //find min in key array set u.
        for(int v =1 ;v <= n ;v ++ ){

            if(mst[v] == false && key[v] < mini ){

                u= v ;
                mini = key[v] ;

            }
        }

    //set true for u  in mst 
        mst[u] = true ;

    //traverse all neighbour of u 
        for(auto it : adj[u] ){

            int v = it.first ;
            int w = it.second ;

        //if neighbour is not visited and w is less than its older value then update.
            if(mst[v] == false && w < key[v]){

                parent[v] = u ;

                key[v] = w ; 

            }

        }
    }

    //use prent array to make ans.
    vector<pair<pair<int, int>, int>> ans ;

    for(int i =2 ;i <= n ; i++ ){

        ans.push_back(make_pair(make_pair(parent[i] , i ) , key[i] )) ;

    }

    return ans ;
}


int main(){

    vector<pair<pair<int, int>, int>> g = 
{
{{1 , 2} ,  2} , 
{{1 , 4} ,  6} , 
{{2 , 1} ,  2} , 
{{2 , 3} ,  3} , 
{{2 , 4} ,  8} , 
{{2 , 5} ,  5} , 
{{3 , 2} ,  3} , 
{{3 , 5} ,  7} , 
{{4 , 1} ,  6} , 
{{4 , 2} ,  8} , 
{{4 , 5} ,  9} , 
{{5 , 2} ,  5} , 
{{5 , 3} ,  7} , 
{{5 , 4} ,  9} 
} ;


    vector<pair<pair<int, int>, int>> ans  = calculatePrimsMST(5,14 , g) ; 


    cout << "u v w" << endl;
    for ( auto i : ans  ){

        cout << i.first.first  << " " << i.first.second << " "<< i.second << endl;
    
    
    
    } cout  << endl;

}