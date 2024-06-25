//p85 -> BFS
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void bfs(vector<vector<int>> &adj , unordered_map<int, bool > &visit , vector<int> &ans ,int i  ){

    //init. queue and push starting elemnt and mark it visited. 
    queue<int> q ;
    q.push(i) ;

    visit[i] = 1 ;

    while(! q.empty()){
        int f = q.front() ; 
        q.pop() ;

    //push front elemrnt to ans. 
        ans.push_back(f) ;


    // push all neighbour of front in queue if not visited and mark it visited. 
        for(auto i : adj[f]) {
            if(! visit[i]){

                q.push(i) ;
                visit[i] = 1 ;
                
            }
        } 
    }
}

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    // Write your code here.

    //vector to store ans .
    vector<int> ans  ;

    // map for identify visited or not. 
    unordered_map<int, bool > visit ;

    //bfs
    bfs(adj , visit , ans , 0 ) ;
    
    
    return ans ; 

}

int main(){

    cout << "Alright !!!!!!!!!" << endl;


}