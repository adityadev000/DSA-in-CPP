//p56 -> q1 -> next Smaller Element
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s ;
    s.push(-1) ;
    vector<int> ans(n) ;
    for(int i = n-1; i>=0  ; i--){
        while (arr[i] <= s.top()) {
            s.pop() ;
        }
        ans[i] = s.top() ;
        s.push(arr[i] ) ;
    }

    return ans  ;

}

int main(){

    vector<int> arr = {2, 1 ,4 ,3} ;
    int n = 4 ;
    vector<int> ans = nextSmallerElement(arr ,n) ;

    for(int i = 0; i< n ; i++){
        cout << ans[i] << " " ; 
    }
    cout << endl;


}