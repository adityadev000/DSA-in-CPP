#include<iostream>
using namespace std;

//p7a -> Switch example
void switchexample (){
    char ch = '1';
    int num = 1;

    cout << endl;
    switch (2 * num)
    {

    case 2:
        cout << "First" << endl;
        cout << " First again " << endl;
        break;

    case '1':
        switch (num)
        {
        case 1:
            cout << " Value of num is " << num << endl;
            break;
        }
        break;

    default:
        cout << " It is default case" << endl;
    }

    cout << endl;
}

//p7b -> calculate power
int power (int a , int b){
    int ans = 1;
    for(int i = 0; i< b ; i++){
        ans  *= a;
    }
    return ans ;
}
//p7c -> calculate factorial
int factorial (int n){
    int ans =1;
    for(int i = 1; i<= n ; i++){
        ans *= i;
    }
    return ans ;
}
//p7d -> calculate nCr
int nCr (int n ,int r){
    int num = factorial (n);
    int denom = factorial (r) * factorial(n-r);
    cout << n<<"C"<<r<< "= " ;
    return num /denom ;
}
//p7e -> check even or not 
bool iseven (int n){
    if (n%2 == 0){
        return 1;
    }
    return 0;
}
//p7f -> check prime or not 
bool isprime (int n){
    for(int i = 2; i< n ; i++){
        if (n %i == 0){
            return 0;
        }
        return 1;
    }
}

//p7g ->  Pass by value
void dummy(int n ) {
    n++;
    cout << "n is " << n <<endl;
}


int main(){
    switchexample() ;
    cout << power (2 ,3) << endl;
    cout << factorial(5) << endl;
    cout << nCr(8,2) << endl;
    cout << iseven(7) << endl;
    cout << isprime(11) << endl;

    
    int n;
    cout << "enter n" << endl;
    cin >> n;
    dummy(n);
    cout<<"number n is "<< n << endl;
}



// HOMEWORK PROBLEM 
/*
#include<iostream>
using namespace std;

int AP (int n){
    return (3*n) +7;
}

int fibonacci (int n){
    int a = 0, b= 1;
    int sum = 0;
    if (n== 2){
        return 1;
    }
    for(int i = 1; i<(n-1)  ; i++){
        sum = (a+b);
        a =b ;
        b = sum ;
    }
    return sum ;
}


int main(){

    cout << AP(3) << endl;
    cout << fibonacci(2) << endl;

}

#include<iostream>
using namespace std;

int main(){

    int n ;
    cout << "enter n" << endl;
    cin>> n;


    int one = n /100;
    int twot = (n-(one*100)); int two = twot/50;
    int threet = ((twot) - (two*50)); int three = threet /20;
    int fourt = ((threet) - (three*20)); int four = fourt /1 ;
    switch (100){
        case 100 :  
                    cout << "number of 100 notes are "<< one << endl;
                    

        case 50 :   
                    cout << "number of 50 notes are "<< two << endl;


        case 20 :   
                    cout << "number of 20 notes are "<< three << endl;


        case 1 :   
                    cout << "number of 1 notes are "<< four << endl;
                    break ;
    }


}
*/
