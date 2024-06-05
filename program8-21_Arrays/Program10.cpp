#include <iostream>
using namespace std;

//p10a -> swapAlternate element 
void swapAlt(int arry[], int n)
{
    // int s = 0, e =1 ;
    for (int i = 0; i < (n - 1); i += 2)
    {
        swap(arry[i], arry[i + 1]);
        // s +=2 ;
        // e +=2 ;
    }
    cout << "after swapping alternate elements new array is " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arry[i] << " ";
    }
    cout << endl<<endl;
}

//p10b -> findUnique in array all elements are
//       two times only one element is one time.
void findUnique(int a[], int n)
{

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[i] == a[j])
            {
                count++;
            }
        }
        if (count == 1)
        {
            cout << "unique element is " << a[i] << endl;
        }
    }
    cout  << endl;
}

//p10c -> duplicate ->all elements are one time time only one element is two time 
void duplicate(int a[], int n)
{
    int ans = 0;

    // XOR ing all array elements
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ a[i];
    }

    // XOR [1, n-1]
    for (int i = 1; i < n; i++)
    {
        ans = ans ^ i;
    }
    cout << "the duplicate element is "<<ans << endl;
    cout  << endl;
}

/*void intersection (int a[],int b [], int na , int nb ){

    for(int i = 0; i< na ; i++){
        for(int j = 0; j< nb ; j++){
            if (a[i] == b[j]){
                cout << a[i] <<" ";
                b[j] = INT32_MIN;
                break ;
            }
        }
    }
}
*/
//p10d -> find intersection of two arrays .
void intersection(int a[], int b[], int n, int m)
{
    int i = 0, j = 0, count = 0, r = 0;
    int ans[n];
    while (i < n && j < m)
    {

        if (a[i] == b[j])
        {
            count++;
            ans[r] = a[i];
            i++;
            j++;
            r++;
        }
        else if (a[i] < b[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    cout << "intersection of two arrays is " << endl;
    for (int i = 0; i < count; i++)
    {
        cout << ans[i] << "  ";
    }
    cout << endl;
}


//p10e- > Pair sum.
void pairSum(int a[], int n, int s)
{
    int ans[2];
    for (int i = 0; i < n; i++)
    {
        for (int j = (i + 1); j < n; j++)
        {
            if (s == (a[i] + a[j]))
            {
                ans[0] = min(a[i], a[j]);
                ans[1] = max(a[i], a[j]);
                cout << "pair sum of "<< s << " is "  ;
                for (int k = 0; k < 2; k++)
                {
                    cout << ans[k] << " ";
                }
                cout << endl<<endl;
            }
        }
    }
}


//p10f -> pair triplet .
void tripletSum(int a[], int n, int s)
{

    int ans[3];
    for (int i = 0; i < n; i++)
    {
        for (int j = (i + 1); j < n; j++)
        {
            for (int k = (j + 1); k < n; k++)
            {
                if (s == (a[i] + a[j] + a[k]))
                {
                    ans[0] = a[i];
                    ans[1] = a[j];
                    ans[2] = a[k];

                    cout << "triplet sum is  : " << endl;
                    for (int i = 0; i < 3; i++)
                    {
                        cout << ans[i] << "  ";
                    }
                    cout << endl;
                }
            }
        }
    }
}

//p10g -> sort 01.
void sortOne(int arr[], int n) {

    int left = 0, right = n-1;

    while(left < right) {

        while(arr[left] == 0 && left < right )  {
            left++;
        }

        while(arr[right]==1 && left < right){
            right--;
        }

        //agar yha pohoch gye ho, iska matlab
        //arr[left]==1 and arr[right]==0
        if(left<right)
        {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
    cout << "printing the array after sorting 0 and 1" << endl;
    for(int i = 0; i< n ; i++){
        cout << arr[i] << " " ;
    }

}


int main()
{

    int arr1[6] = {2, 7, 5, 8, 4, 1};
    int arr2[5] = {2, 7, 5, 8, 4};
    int arr3[7] = {2, 7, 5, 8, 7, 2, 5};
    int arr4[9] = {8, 7, 2, 5, 4, 7, 1, 3, 6};
    int arr5[5] = {1, 2, 3, 4, 5};
    int arr6[3] = {4, 4, 5};
    int arr7[5] = {1,6,3,7,2};
    int arr8[5] = {1, 2, 3, 4, 5};
    int arr9[6] = {0,1,1,0,0,1} ;

    swapAlt(arr1, 6);
    swapAlt(arr2, 5);

    findUnique(arr3, 7);

    duplicate(arr4, 9);

    intersection(arr5, arr6, 5, 3);

    pairSum(arr7, 5, 9);

    tripletSum(arr8, 5, 12);

    sortOne(arr9 ,6);
}
