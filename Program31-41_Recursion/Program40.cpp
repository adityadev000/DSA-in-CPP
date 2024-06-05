//rat in a maze problem  
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool isSafe(int newi ,int newj ,int n ,vector<vector<int>> visited ,vector<vector<int>> m){
    if((newi >= 0 && newi < n) && (newj >= 0 && newj < n) && m[newi][newj] == 1 && visited[newi][newj] == 0) return 1 ;
    return 0 ;
}

void solve (vector<vector<int>> m , int n , int i , int j ,string output ,vector<string>& ans,vector<vector<int>> visited ){
    //base case 
    if(i == n-1 &&   j== n-1) {
        ans.push_back(output) ;
        return ;
    }

    visited[i][j] = 1 ;
    
    //for down 
    int newi = i+1 , newj = j ;
    if(isSafe(newi ,newj , n , visited ,m )){
        output.push_back('D') ;
        solve(m ,n ,newi , newj, output,ans , visited) ;
        output.pop_back() ; // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    }
    //for left 
    newi = i ; newj = j -1 ;
    if(isSafe(newi ,newj , n , visited ,m )){
        output.push_back('L') ;
        solve(m ,n ,newi , newj, output,ans , visited) ;
        output.pop_back() ;
    }
    //for right 
    newi = i ; newj = j +1 ;
    if(isSafe(newi ,newj , n , visited ,m )){
        output.push_back('R') ;
        solve(m ,n ,newi , newj, output,ans , visited) ;
        output.pop_back() ;
    }
    //for up 
    newi = i-1 ; newj = j  ;
    if(isSafe(newi ,newj , n , visited ,m )){
        output.push_back('U') ;
        solve(m ,n ,newi , newj, output,ans , visited) ;
        output.pop_back() ;
    }

    visited[i][j] = 0 ;
}


vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans  ;

        if(m[0][0] == 0) return ans ; 

        string output = "" ;
        vector<vector<int>> visited = m ; // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        for(int i = 0; i< n ; i++){
            for(int j = 0; j< n ; j++){
                visited[i][j] = 0 ;
            }
        }

        int i =0 , j= 0 ;
        solve (m ,n ,i , j, output,ans ,visited) ;
        sort(ans.begin() , ans.end()) ;   // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        return ans  ;
    }

int main(){

    vector<vector<int>> m = {{1,0,0,0} , {1,1,0,1} , {1,1,0,0} , {0,1,1,1} };
    int n = 4 ; 

    findPath(m ,n ) ;
    cout << "Alright!!!!!!!!!!!!!!!!!" << endl;


}