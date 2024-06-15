//p83 -> q ->  The N - Queens Puzzle.
#include<iostream>
#include<bits/stdc++.h>

using namespace std;


bool is_safe(int row ,int col ,vector<vector<int>>& board , int n ){
	int x = row , y= col ;

	//chk for same row 
	while(y >= 0 ){

		if(board[x][y] == 1 ) 
			return false ;

		y--;

	}

	x = row , y= col ;

	//chk for upper diagonal 
	while(x >= 0 && y >= 0 ){

		if(board[x][y] == 1 ) 
			return false ;

		x -- ;
		y -- ;

	}
	

	x = row , y= col ;

	//chk for lower diagonal 
	while(x < n  && y >= 0 ){

		if(board[x][y] == 1 ) 
			return false ;

		x ++ ;
		y -- ;

	}

	return true ;

}

void add_sol(vector<vector<int>>& ans , vector<vector<int>> &board , int n ){

	vector<int> temp ;

	for(int i =0; i< n; i++ ){
		for(int j =0 ;j <n ;j ++ ){

			temp.push_back(board[i][j]) ;

		}
	}

	ans.push_back(temp) ;
	
}

void solve(int col ,vector<vector<int>>& ans , vector<vector<int>>& board , int n  ){

	//base case
	if(col == n ){

		add_sol(ans , board , n ) ;

		return ;

	}
	for(int row = 0; row < n ; row ++ ){

		if(is_safe(row ,col , board , n )){

			board[row][col] = 1 ;

			solve(col+1 , ans , board,n );

			//backtrack ;
			board[row][col] = 0 ;

		}
	}
}

vector<vector<int>> nQueens(int n)
{
	// Write your code here

	vector<vector<int>>  board(n , vector<int>(n,0)) ;

	vector<vector<int>> ans ;

	solve(0, ans , board , n ); 

	return ans ; 
	
}

int main(){

    int n = 4  ;
    vector<vector<int>> ans = nQueens(n) ;

    for(int i = 0; i< ans.size() ; i++){
        for(int j = 0; j< ans[0].size() ; j++){
            cout << ans[i][j] << " "; 
        }cout  << endl;
    }


}