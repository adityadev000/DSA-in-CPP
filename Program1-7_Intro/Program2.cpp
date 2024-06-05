#include<iostream>
using namespace std;

int main(){

// P2a -> ex: of (if and else if block)
    cout << "ex: of (if and else if block)" << endl;
    int a, b;
    cout << "enter the value of a:" << endl;
    cin>>a;
    cout << "enter the value of b:" << endl;
    cin>>b;

    if(a > b){
        cout << "a is greater" << endl << endl;
    }
    else if (b > a){
        cout << "b is greater" << endl << endl;
    }
    else {
        cout << "both are equal" << endl << endl;
    }

//While loops

//P2b -> Print 1 to n
    cout << "Print 1 to n:" << endl;
    int n;
    cout << "enter the value of n:" << endl;
    cin >> n;
    int x =1 ;
    while (x <= n){
        cout << x << endl << endl;
        x++;
    }

//P2c -> Print sum of 1 to m
    cout << "Print sum of 1 to m" << endl;
    int m;
    cout << "enter the value of m:" << endl;
    cin >> m;
    int y =1 , sum =0;
    
    while (y <= m){
        sum += y;
        y++;
    }
    cout << sum << endl << endl;

//P2d ->sum of m even no.
    cout << "sum of m even no." << endl;
    int num;
    cout << "enter the value of num:" << endl;
    cin >> num;
    int z =2 , sumeven =0;
    
    while (z <= num){
        sumeven += z;
        z = z+2;
    }
    cout << sumeven << endl << endl;

//P2e -> farenheit to celcius
    cout << "farenheit to celcius" << endl;
    float farenheit;
    cout << "Enter the data in farenheit:" << endl;
    cin>>farenheit;
    float celcius = ((farenheit-32)*5)/9;
    cout << "the in celcius is "<< celcius << endl << endl;


//P2f -> check given no. is prime or not 
cout << "check given no. is prime or not :" << endl;
    int checkprime;
    cout << "enter any integer" << endl;
    cin >> checkprime;
    int s = 2, count = 0;
    while (s < checkprime){
        if (checkprime % s == 0){
            count ++;
        }
        s++;
    }
    if (count == 0){
        cout << "number is prime :)" << endl << endl;
    }
    else {
        cout << "Number is not prime :(" << endl << endl;
    }


//P2g -> Pattern1
    cout << "Pattern1" << endl;
    int n1;
    cout << "Enter n1" << endl;
    cin>>n1;
    int n1i = 0;
    while (n1i < n1){
        int n1j = 0;
        while (n1j < n1){
        cout << "*" ;
        n1j ++;
        }
        cout  << endl;
        n1i ++;
    } 

////P2h -> Pattern2
    cout << "Pattern2" << endl;
    int n2;
    cout << "Enter n2 " << endl;
    cin>>n2;
    int n2i = 1;
    while(n2i <= n2){
        int n2j = 1;
        while (n2j <= n2){
            cout << n2i ;
            n2j ++;
        }
        cout  << endl;
        n2i ++;
    }
    
//HOMEWORK PROBLEM 1
    cout << "Identify the char is in uppercase, lowecase or in numeric" << endl;
    char ch;
    cout << "enter the char" << endl;
    cin >> ch;
    int a = ch ;

    if(a >=97 && a <= 122){
        cout << "This char is of lowercase" << endl;
    }
    if(a >=65 && a <= 90){
        cout << "This char is of uppercase" << endl;
    }
    if(a >=48 && a <= 57){
        cout << "This char is of numeric" << endl;
    }
}