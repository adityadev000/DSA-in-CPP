//p57 -> max rectangle.
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int> rightnextsmallerindex(int* heights, int n) {
       stack<int> s;
       s.push(-1);
       vector<int> ans(n);
       for (int i = n - 1; i >= 0; i--) {
           while (s.top() != -1 && heights[i] <= heights[s.top()]) {
               s.pop();
           }
           ans[i] = s.top();
           s.push(i);
       }
       return ans;
   }


vector<int> leftnextsmallerindex(int* heights, int n) {
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        while (s.top() != -1 && heights[i] <= heights[s.top()]) {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int largestRectangleArea(int* heights , int n ) {
    int area = INT_MIN;
    vector<int> left(n);
    vector<int> right(n);
    left = leftnextsmallerindex(heights, n);
    right = rightnextsmallerindex(heights, n);
    for (int i = 0; i < n; i++) {
        if(right[i] == -1) right[i] = n;
        int newarea = heights[i] * (right[i] - left[i] - 1);
        area = max(area, newarea);
    }
    return area;
}

int maxArea(int M[4][4], int n, int m) {
       int area = largestRectangleArea(M[0] , m ) ;

       for(int i = 1; i< n ; i++){
            for(int j = 0; j< m ; j++){
                
            
                if(M[i][j] != 0  ) 
                    M[i][j] = M[i][j] +  M[i-1][j] ; 
                
                else 
                    M[i][j] = 0;
    
            }
            area = max(area ,largestRectangleArea(M[i] , m)) ;
       }
       return area ;
}

int main(){

    int M[4][4] = 
    {{0, 1 ,1, 0},
    {1 ,1 ,1, 1},
    {1 ,1 ,1 ,1},
    {1 ,1 ,0 ,0}} ;

    cout << maxArea(M , 4,4) << endl;
}