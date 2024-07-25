//p107 -> dp06 ->   Cut rod Into Segments x ,y ,z .
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int solve_rec(int n, int x, int y, int z) {

    // base case
    // Yadi n 0 hai, to 0 return karo
	if(n == 0 ) return 0 ;
    
    // Yadi n negative hai, to INT_MIN return karo (invalid case)
	if(n < 0 ) return INT_MIN ;

    // Calculation of options a, b, c
	int a = solve_rec(n-x , x ,y, z ) + 1 ;
	int b = solve_rec(n-y , x ,y, z ) + 1 ;
	int c = solve_rec(n-z , x ,y, z ) + 1 ;

    // Calculate maximum of a, b, c
	int ans =  max(a , (max(b,c ))) ;

	return ans ; 
}


int solve_rec_memo(int n, int x, int y, int z ,vector<int>&dp ){

	//baaase case 
	if(n == 0 ) return 0 ;
	if(n < 0 ) return INT_MIN ;
	if(dp[n] != -1) return dp[n] ; 

	int a = solve_rec_memo(n-x , x ,y, z,dp  ) +1 ;
	int b = solve_rec_memo(n-y , x ,y, z,dp  ) +1 ;
	int c = solve_rec_memo(n-z , x ,y, z ,dp ) +1 ;

	dp[n] =  max(a , (max(b,c ))) ;

	return dp[n] ; 
}

int solve_tabulisation(int n, int x, int y, int z  ){
	
	vector<int> dp(n+1 , -1) ;

	dp[0] = 0 ;

	for(int i =1 ; i<= n; i++ ){
		
		if(i-x >= 0 && dp[i-x] != -1 ){

			dp[i] = max(dp[i] , dp[i-x] +1 ) ;
		}
		if(i-y >= 0 && dp[i-y] != -1 ){

			dp[i] = max(dp[i] , dp[i-y] +1 ) ;
		}
		if(i-z >= 0 && dp[i-z] != -1 ){

			dp[i] = max(dp[i] , dp[i-z] +1 ) ;
		}

	}

	if(dp[n] < 0 ) return 0 ;


	return dp[n] ; 
}



int cutSegments(int n, int x, int y, int z) {

	// int ans = solve_rec(n,x,y,z) ;

	// if(ans < 0 ) return 0 ;

	// else return ans ; 

	// vector<int> dp(n+1 , -1) ;
	// int ans = solve_rec_memo(n,x,y,z ,dp) ;

	// if(ans < 0 ) return 0 ;

	// else return ans ;

	return solve_tabulisation(n ,x ,y,z ); 
}


int main(){

    cout << cutSegments(7,5,2,2) << endl;


}