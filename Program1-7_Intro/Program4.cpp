#include<iostream>
using namespace std;

int main(){
    int a = 4;
    int b = 6;

//p4a -> Bitwise operator.
    cout << "(a&b) " << (a&b) << endl;
    cout << "(a|b) " << (a|b) << endl;
    cout << "(~a) " << (~a) << endl;
    cout << "(a^b) " << (a^b) << endl;

//p4b ->right shift and left shift.
    cout << (17>>1) << endl;
    cout << (17>>2) << endl;
    cout << (17<<1) << endl;
    cout << (17<<2) << endl;


//p4c ->Print fibbonacci numbers
    int n =10;
    int num1 = 0;
    int num2 = 1;
    cout << num1 << " " << num2 << " " << endl;
    for(int i = 1; i<= n ; i++){
        int nxtnum = (num1+num2);
        cout << nxtnum << " " ;
        num1= num2 ;
        num2 = nxtnum;
    }
return 0;
}