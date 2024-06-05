#include <iostream>
using namespace std;

// p14a
int pivot(int a[], int n)
{
    int s = 0, e = (n - 1);
    int mid = s + (e - s) / 2;
    while (s < e)
    {
        if (a[mid] < a[0])
        {
            e = mid;
        }
        else
        {
            s = (mid + 1);
        }
        mid = s + (e - s) / 2;
    }
    return s;
}
// p14b
int FindInRotatedAndSortedArray(int a[], int n, int key)
{
    int s = 0, e = (n - 1);
    int mid = s + (e - s) / 2;

    if (key < a[0])
    {
        s = pivot(a, n);
        mid = s + (e - s) / 2;

        while (s <= e)
        {
            if (key == a[mid])
            {
                return mid;
            }
            if (key > a[mid])
            {
                s = (mid + 1);
            }
            else
            {
                e = (mid - 1);
            }
            mid = s + (e - s) / 2;
        }
    }
    else
    {
        e = pivot(a, n);
        mid = s + (e - s) / 2;
        while (s <= e)
        {
            if (key == a[mid])
            {
                return mid;
            }
            if (key > a[mid])
            {
                s = (mid + 1);
            }
            else
            {
                e = (mid - 1);
            }
            mid = s + (e - s) / 2;
        }
    }
    return -1;
}

// p14c
long long int sqRootBinarySearch(int n)
{

    int s = 0, e = n;
    long long int mid = s + (e - s) / 2;
    long long int square = (mid * mid);
    long long int ans = 0;
    while (s <= e)
    {
        if (square == n)
        {
            return mid;
        }
        if (square < n)
        {
            ans = mid;
            s = (mid + 1);
        }
        else
        {
            e = (mid - 1);
        }
        mid = s + (e - s) / 2;
        square = (mid * mid);
    }
    return ans;
}

float precision(int n, int precision, int tempsol)
{

    double factor = 1;
    double ans = tempsol;
    for (int i = 0; i < precision; i++)
    {
        factor /= 10;
        for (double j = ans; j * j < n; j += factor)
        {
            ans = j;
        }
    }
    return ans;
}

int main()
{

    int arr[8] = {6, 9, 10, 11, 2, 3, 4, 5};
    // cout << pivot (arr ,8) << endl;
    cout << "elemnt present at index " << FindInRotatedAndSortedArray(arr, 8, 11) << endl;

    int n;
    cout << "enter a number " << endl;
    cin >> n;
    int tempsol = sqRootBinarySearch(n);
    cout << "ans is " << precision(n, 3, tempsol) << endl;
}
