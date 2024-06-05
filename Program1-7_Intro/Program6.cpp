#include<iostream>
using namespace std;

//p6a
  int reverse(int x) {
        int ans = 0;
        while (x != 0){
            int digit = x % 10 ;
            if ((ans > (INT32_MAX / 10)) || (ans < (INT32_MIN / 10))){
                return 0;
            }
            ans = (ans * 10 ) + digit ;
            x /= 10 ;
        }
            return ans ;
       return 0;
    }

//p6b
    int bitwiseComplement(int n) {
        int m = n ;
        int mask = 0; 
        if ( n == 0){
            return 1;
        }
        while (m !=0 ){
            mask = (mask << 1) | 1 ;
            m = m >> 1 ;
        }
        int ans = (~n) & mask ;
        return ans ;        
    }

//p6c
    bool isPowerOfTwo(int n) {
        if (n == 1) {
            return true;
        }
        if (n == 0) {
            return false;
        }
        while (n > 0) {
            int rem = n % 2;
            if (rem == 0) {
                n = n / 2;
                if (n == 1) {
                    return true;
                }
            } else {
                return false;
            }
        }
        return true;
    }

    int main(){
    cout << "reverse integer" << endl;
    cout << reverse (123)<< endl;
    cout << reverse (-123)<< endl;
    cout << reverse (120)<< endl;


    cout << "bitwiseComplement" << endl;
    cout << bitwiseComplement(5) << endl;


    cout << "isPowerOfTwo" << endl;
    cout << isPowerOfTwo (16) << endl;
    cout << isPowerOfTwo (18) << endl;
    cout << isPowerOfTwo (17) << endl;
    cout << isPowerOfTwo (0) << endl;
    cout << isPowerOfTwo (1) << endl;
}

