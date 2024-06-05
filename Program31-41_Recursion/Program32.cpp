#include<iostream>
#include<bits/stdc++.h>

using namespace std;
//p32a
int fib(int n) {
        if(n == 0){
            return 0 ;
        }
        if(n == 1){
            return 1 ;
        }
        return fib(n-1) + fib(n-2) ;
    }

//p32b
int countDistinctWayToClimbStair(long long nStairs)
{
    //base case
    if(nStairs < 0)
        return 0;
    
    if(nStairs == 0)
        return 1;
    
    //R.C
    int ans = countDistinctWayToClimbStair(nStairs-1) 
        + countDistinctWayToClimbStair(nStairs-2);
    
    return ans;
}

// p32c
void sayDigit(int n, string arr[]) {

    //base case
    if(n == 0)
        return ;

    //processing 
    int digit = n % 10;
    n = n / 10;
    

    //recursive call
    sayDigit(n, arr);

    cout << arr[digit] << " ";

}

int main(){


    cout << countDistinctWayToClimbStair(4) << endl ; 


    string arr[10] = {"zero", "one", "two", "three",
                         "four", "five", "six"
                        , "seven", "eight", "nine"};
    int n;
    cin >> n;

    cout << endl  ;
    sayDigit(n, arr);
    cout << endl  ;


}