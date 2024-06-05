#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

void print(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
            cout << arr[i] << " ";
    }
}

//p23a
void largest_row_Sum(int arr[][3], int row, int col)
{
    int maxi = 0, index = -1;
    for (int i = 0; i < row; i++)
    {
        int sum = 0;
        for (int j = 0; j < col; j++)
        {
            sum += arr[i][j]; // sum row wise
            // sum  += arr[j][i] ;//sum col wise
        }
        if (sum > maxi)
        {
            maxi = sum;
            index = i;
        }
        cout << "sum = " << sum << endl;
    }
    cout << "max  sum = " << maxi << " for row no. " << index + 1 << endl;
}

//p23b
vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector<int> p;
    for (int i = 0; i < mCols; i++)
    {
        if ((i % 2) == 0)
        {
            for (int j = 0; j < nRows; j++)
            {
                p.push_back(arr[j][i]);
            }
        }
        else
        {
            for (int j = nRows - 1; j >= 0; j--)
            {
                p.push_back(arr[j][i]);
            }
        }
    }
    return p;
}

//p23c
vector<int> spiralOrder(vector<vector<int>> &matrix){
    vector<int> p;
    int r = matrix.size();
    int c = matrix[0].size();
    int x = 0, y = 0;
    int i = 0, j = 0;
    int total = (r * c);
    int count = 0;
    while ((count) < total)
    {
        while (j < (c - x) && (count < total))
        {
            p.push_back(matrix[i][j]);
            count++;
            j++;
        }

        j--;
        i++;
        while (i < (r - y) && (count < total))
        {
            p.push_back(matrix[i][j]);
            count++;
            i++;
        }

        i--;
        j--;
        while (j >= x && (count < total))
        {
            p.push_back(matrix[i][j]);
            count++;
            j--;
        }

        j++;
        i--;
        while (i > y && (count < total))
        {
            p.push_back(matrix[i][j]);
            count++;
            i--;
        }
        i++;
        j++;

        x++;
        y++;
    }

    return p;
}

//p23d
bool binary_searchMatrix(vector<vector<int>> &matrix, int target){
    int r = matrix.size();
    int c = matrix[0].size();
    int s = 0, e = (r * c - 1);
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        int index = matrix[mid / c][mid % c];
        if (index == target)
        {
            return 1;
        }
        else if (index > target)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return 0;
}

//p23e
bool advance_searchMatrix(vector<vector<int>> &matrix, int target){
    int r = matrix.size();
    int c = matrix[0].size();
    int i = 0, j = c - 1;
    while (i < r && j >= 0)
    {
        int index = matrix[i][j];
        if (index == target)
        {
            return 1;
        }
        else if (index < target)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return 0;
}

//hw rotate matrix 90 degree
void rotate(vector<vector<int>>& matrix) {
    int r= matrix.size(); 
    int c = matrix[0].size() ;
    int row = 0  , col = 0 ;
    int i = 0 ,j = 0; 

    while (row < r ){
        i =row ;
        j = col ;

        while (i < r && j < c){
            swap(matrix[row][i] , matrix[j][col]) ;
            i ++ ;
            j ++ ;
        }
        row ++ ;
        col ++ ;
    }
    int nrow = 0 ;
    while (nrow <r){
        int i = 0, j = c-1 ;
        while (i<=j) {
            swap(matrix[nrow][i],matrix[nrow][j]);
            i ++ ;
            j -- ;
        }
        nrow ++ ;
    }
}

int main()
{
//p23a
    int row = 3, col = 3;
    int arr[3][3];

    cout << "enter " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }
    largest_row_Sum(arr, row, col);

//p23b
    cout << "wave print" << endl;
    vector<vector<int>> v1 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    vector<int> wave = wavePrint(v1, 3, 4);
    print(wave) ;
    cout  << endl;

//p23c
    cout<< "spiral order " << endl;
    vector<int> spiral = spiralOrder(v1);
    print (spiral) ;
    cout  << endl;
//p23d
    vector<vector<int>> v2 = {{1,3,5,7}, {10,11,16,20}, {23,30,34,60}};
    cout << binary_searchMatrix(v2 ,3 ) << endl;
    cout  << endl;
//p23e
    vector<vector<int>> v3 ={ {1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}} ;
    cout << binary_searchMatrix(v3 ,5 ) << endl;

}