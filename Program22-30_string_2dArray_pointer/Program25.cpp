#include <iostream>
using namespace std;
// p-> 25
int main()
{

    int num = 5;

    cout << num << endl;

    // address of Operator - &

    cout << " address of num is " << &num << endl;

    int *ptr = &num;

    cout << "Address is : " << ptr << endl;
    cout << "value is : " << *ptr << endl;

    double d = 4.3;
    double *p2 = &d;

    cout << "Address is : " << p2 << endl;
    cout << "value is : " << *p2 << endl;

    cout << " size of integer is " << sizeof(num) << endl;
    cout << " size of pointer is " << sizeof(ptr) << endl;
    cout << " size of pointer is " << sizeof(p2) << endl;

    // pointer to int is created, and pointing to some garbage address
    // int *p = 0;

    // cout << *p << endl;

    /*
    int i = 5;

    int *q = &i;
    cout << q << endl;
    cout << *q << endl;

    int *p = 0;
    p = &i;

    cout << p << endl;
    cout << *p << endl;
    */

    int num1 = 5;
    int a = num1;
    cout << "a before " << num1 << endl;
    a++;
    cout << "a after " << num1 << endl;

    int *p = &num;
    cout << "before " << num1 << endl;
    (*p)++;
    cout << "after " << num1 << endl;

    // copying a pointer
    int *q = p;
    cout << p << " - " << q << endl;
    cout << *p << " - " << *q << endl;

    // important concept
    int i = 3;
    int *t = &i;
    // cout <<  (*t)++ << endl;
    *t = *t + 1;
    cout << *t << endl;
    cout << " before t " << t << endl;
    t = t + 1;
    cout << " after t " << t << endl;

    return 0;
}