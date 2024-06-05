//p76 -> q2 -> Merge K Sorted Arrays.
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class node{
    public :
        int data ;
        int i ;
        int j ;

        node (int data ,int r ,int c ){
            this  -> data = data ;
            i =r  ;
            j = c ;
        }
};

class compare {
    public :
    bool operator () (node * a , node * b) {
        return a-> data > b-> data ;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    priority_queue<node* , vector<node * > , compare > mh ;

    for(int i =0 ;i < k ; i++ ){
        node * tmp = new node (kArrays[i][0] , i , 0 );
        mh.push (tmp) ;
    }

    vector <int> ans  ;

    while (!mh.empty() ){
        node * tmp = mh.top() ;
        ans.push_back(tmp -> data ) ;
        mh.pop() ;

        int i = tmp -> i ;
        int j = tmp -> j ;
        if(j+1 < kArrays[i] .size() ){
            node * next = new node (kArrays[i][j+1] , i , j+1) ;
            mh.push(next );
        }
    }
    return ans ; 
}


int main(){

    vector<vector<int>> a = {{1,2,3,6} , {4,8,9} , {5,10,12} } ;

    vector<int> ans = mergeKSortedArrays(a , 3) ;

    for(auto i : ans ){
        cout << i << " " ;
    }cout  << endl;


}