//p138 -> dp37-> Maximal rectangle.
#include<iostream>
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
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int maxi =INT_MIN ;

        vector<int> area(matrix[0].size()) ;

        for(int i =0 ;i< matrix.size() ; i++ ){

            for(int j = 0 ; j< area.size() ; j ++ ){

                if(matrix[i][j] == '1'){
                    area[j] ++ ;
                }
                else area[j] =0 ;

            }

            maxi = max(maxi , largestRectangleArea(area)) ;
        }
        return maxi ;
    }


int main(){

     vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    int result = maximalRectangle(matrix);
    cout << "The maximal rectangle area is: " << result << endl;



}