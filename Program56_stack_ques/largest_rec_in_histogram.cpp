//p56 -> q2 -> Largest Rectangle in Histogram
#include<iostream>
#include<stack> 
#include<bits/stdc++.h>

using namespace std;
 vector<int> rightnextsmallerindex(vector<int>& heights, int n) {
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

vector<int> leftnextsmallerindex(vector<int>& heights, int n) {
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

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
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


int main(){

     vector<int> arr = {2,1,5,6,2,3} ;
     cout << largestRectangleArea(arr) << endl;


}