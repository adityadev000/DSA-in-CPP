#include<iostream>
#include<bits/stdc++.h>

using namespace std;
//p24a
bool isPrime(int n) {

    if(n<=1)
    return false;

    for(int i=2; i<n; i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}

//p24b
int countPrimes(int n) {
        int cnt = 0 ;
        vector<bool> prime ((n+1) , true); 
        prime[0] = prime[1] = false ;
        for(int i = 2 ; i < n ; i ++ ){
            if (prime[i]){
                cnt ++ ;
                for(int j = (2*i) ; j < n ; j = j+i){
                    prime[j] = 0 ;
                }
            }
        }
        return cnt ;
}

//p24c
int gcd(int a, int b) {

    if(a==0)
    return b;

    if(b==0)
    return a;

    while(a != b) {

        if(a>b)
        {
            a = a-b;
        }
        else{
            b = b-a;
        }
    }
    return a;
}

//p25d
int fastExpo(int a, int b ) {

    int res = 1;

    while(b > 0) {

        if(b&1) {
            //odd
            res = res*a;
        }
        b = b >> 1;
        a = a * a; 
    }
    return res;
}

int main(){

    cout << countPrimes(40) << endl;


    cout << "gcd =  " << gcd(24 ,72) << endl;


    cout << isPrime(78) << endl;

    cout << fastExpo(2,10) << endl;


}