#include<iostream>
#include<math.h>
using namespace std;

int main(){
//p5a
// DECIMAL TO BINARY:)
    int n ;
    cout << "enter a decimal number" << endl;
    cin >> n ;
    float ans = 0;
    int i = 0;
    while (n != 0){
        int bit = (n&1);
        ans = (bit * pow(10 ,i)) + ans ;
        n = n >> 1;
        i ++ ;
    }
    cout << "the binary represantation of the above number is: " << ans  << endl;
    cout  << endl;
//p5b
//BINARY TO DECIMAL :)
    int m ;
    cout << "enter a  binary  number" << endl;
    cin >> m;
    int answ = 0 ;
    int j =0 ;
    while (m != 0){
        int digit = (m%10);
        if (digit == 1){
            answ = (digit * pow (2,j)) + answ;
        }
        j ++ ;
        m /= 10;
    }
    cout << "The decimal represation is : " << answ << endl;

    cout << "Thankyou !!!!" << endl;
}