//p57 -> The Celebrity problem.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

 bool knows (vector<vector<int> >& M, int n ,int a ,int b ) {
    if(M[a][b] == 1) return 1 ;
    return 0 ;
}

int celebrity(vector<vector<int> >& M, int n) 
    {
        stack <int> s  ;
        for(int i = 0; i< n ; i++){
            s.push(i) ;
        }

        while(s.size() > 1 ){
            int a = s.top() ;
            s.pop() ;

            int b = s.top() ;
            s.pop() ;

            if(knows( M,n,  a,b)) {
                s.push(b) ;
            }
            else {
                s.push(a); 
            }
        }
        int ans = s.top() ;

        int rowcheck = 0 ;
        for(int i = 0; i< n ; i++){
            if(M[ans] [i] == 0 )
            rowcheck ++ ;
        }
        if(rowcheck  != n ) return -1 ;

        int colcheck = 0 ;
        for(int i = 0; i< n ; i++){
            if(M[i] [ans] == 1 )
            colcheck ++ ;
        }
        if(colcheck != n-1) return -1 ;


        return ans ;
    }


int main(){


    vector<vector<int> >  M = 
    {{0, 1 ,0},
    {0 ,0 ,0}, 
    {0 ,1 ,0}} ;

    int n = 3 ;

    cout << celebrity(M,n) << endl;

        
}

