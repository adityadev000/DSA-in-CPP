//p31 RECURSION 
#include<iostream> 
using namespace std;

//p31a -> power 
int power(int n) {

    //base case 
    if(n == 0)
        return 1;

    //recursive relation
    return 2 * power(n-1);    
}


//p31b -> factorial
int factorial(int n) {
    
    //base case
    if(n==0)
        return 1;

    int smallerProblem = factorial(n-1);   
    int biggerProblem = n * smallerProblem;

    return biggerProblem;
}

int main() {

    int n;
    cin >> n;

    int ans = power(n);

    cout << ans << endl;

    int m;
    cin >> m;

    int anss = factorial(n);

    cout << anss << endl;

    return 0;
}


