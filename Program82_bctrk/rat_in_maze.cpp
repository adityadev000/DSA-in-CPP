//p82 -> q-> Rat in a Maze problem. 
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
#include <bits/stdc++.h> 

bool isSafe(int x,int y, vector < vector < int >>& arr, int n, vector<vector<bool>>& visited){

    return ((x>=0 && x<n)&&(y>=0 && y<n)&&(arr[x][y]==1)&&(visited[x][y]==0));

}

void solve(int x, int y, vector < vector < int >> & arr, int n, vector<string> &ans,

            vector<vector<bool>> &visited, string path){

                if(x == n-1 && y == n-1){

                    ans.push_back(path);

                    return;

                }

 

                visited[x][y]=1;

                if(isSafe(x+1,y,arr,n,visited))

                    solve(x+1,y,arr,n,ans,visited,path+'D');

                if(isSafe(x,y-1,arr,n,visited))

                    solve(x,y-1,arr,n,ans,visited,path+'L');

                if(isSafe(x,y+1,arr,n,visited))

                    solve(x,y+1,arr,n,ans,visited,path+'R');

                if(isSafe(x-1,y,arr,n,visited))

                    solve(x-1,y,arr,n,ans,visited,path+'U');

 

                visited[x][y]=0;

            }

vector < string > searchMaze(vector < vector < int >> & arr, int n) {

    // Write your code here.

    vector<string> ans;

    vector<vector<bool>> visited(n,vector<bool>(n,0));

    string path="";

    if(arr[0][0]==0)

    return ans;

 

    if(arr[0][0]==1)

    solve(0,0,arr,n,ans,visited,"");

    

    return ans;

}


int main(){

    vector < vector < int >>   arr =  
{{1, 0 ,0, 0},
{1, 1 ,0 ,0},
{1 ,1 ,0 ,0},
{0 ,1 ,1 ,1}} ;

    vector<string >ans =  searchMaze(arr , 4) ; 
    for(auto i: ans ){
        cout << i << endl;
    }

}