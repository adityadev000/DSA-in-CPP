//p110 -> dp09 ->   Knapsack problem
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h> 

#include <bits/stdc++.h> 

int solve_rec(vector<int>& weight, vector<int>& value, int index, int capacity) {

    //base case
    // if index 0 hai
	if(index == 0 ){
        // Agar weight[index] capacity se kam ya barabar hai
		if(weight[index] <= capacity ){
            // Value[0] return karo (Maximum value jo single item le sakte hain)
			return value[0] ; 
		}
        // Agar weight[index] capacity se zyada hai
		else return 0 ; 
	}

	int incl = 0;

    // Agar current item ka weight capacity se kam ya barabar hai
	if(weight[index] <= capacity ){
        // Inclusion case: Current item ko pick karke recursion call karo
		incl = value[index] + solve_rec(weight, value, index - 1, capacity - weight[index]); 
	}

    // Exclusion case: Current item ko nahi pick karke recursion call karo
	int excl = 0 + solve_rec(weight, value, index - 1, capacity);

    // Maximum value return karo inclusion aur exclusion me se
	return max(incl, excl);
}


int solve_rec_memo(vector<int> &weight, vector<int> &value, int index ,  int capacity ,vector<vector<int>>& dp){

	//base case
	if(index == 0 ){
		if(weight[index] <= capacity ){
			return value[0] ; 
		}
		else return 0 ; 
	}

	if(dp[index][capacity] != -1) {
		return dp[index][capacity];
	}


	int incl =0 ;

	if(weight[index] <= capacity ){
		incl = value[index] + solve_rec_memo(weight ,value ,index -1 , capacity- weight[index],dp ) ; 
	}

	int excl = 0 + solve_rec_memo(weight ,value ,index -1 , capacity ,dp) ;

	dp[index][capacity] =  max(incl ,excl ) ;

	return dp[index][capacity];
}


int solve_tabulisation(vector<int> &weight, vector<int> &value, int n ,  int capacity ){

	vector<vector<int>> dp(n , vector<int>(capacity+1 , 0)) ;

	for(int w =weight[0] ; w <= capacity ;w ++ ){

		if(weight[0] <= capacity ){

			dp[0][w]= value[0] ;

		}
		else dp[0][w] = 0; 
	}

	for(int index = 1 ;index < n ;index  ++ ){

		for(int w =0  ; w <= capacity ;w ++ ){

            int incl = 0; 

			if(weight[index] <= w ){
				incl = value[index] + dp[index-1][w-weight[index]] ; 
			}

			int excl = 0 + dp[index-1][w] ;

			dp[index][w] = max(incl ,excl ) ; 


		}
	}

	return dp[n-1][capacity] ;

}

int solve_opt_less(vector<int> &weight, vector<int> &value, int n ,  int capacity ){


	vector<int> prev(capacity+1 ,0 ); 
	vector<int> curr(capacity+1 , 0 ); 

	for(int w =weight[0] ; w <= capacity ;w ++ ){

		if(weight[0] <= capacity ){

			prev[w]= value[0] ;

		}
		else prev[w] = 0; 
	}

	for(int index = 1 ;index < n ;index  ++ ){

		for(int w =capacity  ; w >=0  ;w -- ){

            int incl = 0; 

			if(weight[index] <= w ){
				incl = value[index] + prev[w-weight[index]] ; 
			}

			int excl = 0 + prev[w] ;

			curr[w] = max(incl ,excl ) ; 



		}
			prev =curr ; 
	}

	return prev[capacity] ;

}
int solve_optimised(vector<int> &weight, vector<int> &value, int n ,  int capacity ){

	// vector<vector<int>> dp(n , vector<int>(capacity+1 , 0)) ;

	// vector<int> prev(capacity+1 ,0 ); 
	vector<int> curr(capacity+1 , 0 ); 

	for(int w =weight[0] ; w <= capacity ;w ++ ){

		if(weight[0] <= capacity ){

			curr[w]= value[0] ;

		}
		else curr[w] = 0; 
	}

	for(int index = 1 ;index < n ;index  ++ ){

		for(int w =capacity  ; w >=0  ;w -- ){

            int incl = 0; 

			if(weight[index] <= w ){
				incl = value[index] + curr[w-weight[index]] ; 
			}

			int excl = 0 + curr[w] ;

			curr[w] = max(incl ,excl ) ; 

			// prev =curr ; 


		}
	}

	return curr[capacity] ;

}



int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{

	// return solve_rec(weight ,value , n-1, maxWeight) ;

	// vector<vector<int>> dp(n , vector<int>(maxWeight+1 , -1)) ;
	// return solve_rec_memo(weight ,value , n-1, maxWeight , dp) ;


	// return solve_tabulisation(weight ,value , n, maxWeight) ;

	// return solve_opt_less(weight ,value , n, maxWeight) ;

	
	return solve_optimised(weight ,value , n, maxWeight) ;



}


int main() {
    int n = 4;
    vector<int> weight = {1, 2, 4, 5};
    vector<int> value = {5, 4, 8, 6};
    int maxWeight = 5;

    int max_value = knapsack(weight, value, n, maxWeight);
    cout << "The maximum value that can be obtained is: " << max_value << endl;

}