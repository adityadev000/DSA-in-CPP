//p77 -> q1 ->  Smallest Range From K Sorted List
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class node {
    public :
    int data ;
    int row ;
    int col ;

    node (int d ,int r ,int c ){
        data = d ;
        row = r ;
        col = c ;
    }
};

class compare {
    public :
    bool operator () (node * a , node * b) {
        return a-> data > b-> data ;
    }
};

int kSorted(vector<vector<int>> &a, int k, int n) {
    // Write your code here.
    int maxi = INT_MIN;
    int mini = INT_MAX;

    priority_queue<node* , vector<node * > , compare > mh ; ;

    for(int i =0 ; i< k ;i++ ){
        int element = a[i][0] ;
        maxi= max(maxi , element);
        mini= min(mini,element) ;
        node* nn = new node (element ,i ,0 );
        mh.push(nn) ;
    }

    int s = mini , e =maxi ;

    while(! mh.empty() ){
        node * tmp = mh.top() ;
        mh.pop() ;
        mini = tmp -> data ;

        if(maxi - mini < (e -s )){
            s =mini ;
            e =maxi ;
        }
        if(tmp -> col+1 < n ){
            maxi = max (maxi , a[tmp->row][tmp->col+1] ) ;
            node* nn = new node (a[tmp->row][tmp->col+1], tmp -> row , tmp -> col +1) ;
            mh.push(nn);
        }
        else{
            break ;
        }
    }
        return (e-s +1 ) ;

}

int main(){

    vector<vector<int>> a = {{1,2,3,6} , {4,8,9,18} , {5,10,12,34} } ;

    cout << kSorted(a , 3 ,4 ) << endl;



}