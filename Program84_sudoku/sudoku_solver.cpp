//p84 -> sudoku solver
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool is_safe(int row ,int col ,vector<vector<int>>& sudoku , int val  ){
    for(int i =0 ; i< 9; i++ ){
        //row chk 
        if(sudoku[row][i] == val ) return false ;

        //col chk
        if(sudoku[i][col] == val ) return false  ;

        //matrix chk 
        if(sudoku[3*(row/3) + (i/3)]   [3* (col/3) + (i%3)] == val ) return false ; 

    }
    //all passed
    return true ; 
}

bool solve(vector<vector<int>>& sudoku) {

    int n = sudoku.size() ;  

    for(int row = 0 ; row < n ; row ++ ){
        
        for(int col = 0 ; col < n ; col ++  ){
            
            if(sudoku[row][col] == 0   ){

                //1 se 9 tk sarii value dall k dekh rhe h kon fit baith rha h 
                for(int val = 1 ; val < 10 ;val ++ ){

                    if(is_safe(row ,col , sudoku , val )){
                        
                        sudoku[row][col] = val ;

                        //recusive calls
                        bool agge_possible = solve(sudoku) ;

                        if(agge_possible) return true ;

                        else 
                        //backtrack
                        sudoku[row][col] = 0 ;

                    }
                }
                return false ; 
            }

        }
    }
    return true ; 
}

void solveSudoku(vector<vector<int>>& sudoku)
{

    solve(sudoku) ;
}

int main(){
    vector<vector<int>> s = 
{ 
{3 ,0,6, 5, 0, 8, 4, 0, 0},
{5 ,2,0, 0, 0, 0, 0, 0, 0},
{0 ,8,7, 0, 0, 0, 0, 3, 1},
{0 ,0,3, 0, 1, 0, 0, 8, 0},
{9 ,0,0, 8, 6, 3, 0, 0, 5},
{0 ,5,0, 0, 9, 0, 6, 0, 0},
{1 ,3,0, 0, 0, 0, 2, 5, 0},
{0 ,0,0, 0, 0, 0, 0, 7, 4},
{0 ,0,5, 2, 0, 6, 3, 0, 0}
} ;

    solveSudoku(s) ;

    for(int i = 0; i< 9 ; i++){
        for(int j = 0; j< 9 ; j++){
            cout << s[i][j] << " " ;
        }cout  << endl;
    }
   
}