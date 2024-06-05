//p55 -> q8 ->  Minimum Cost To Make String Valid
#include<iostream>
#include<stack>

using namespace std;

int findMinimumCost(string str) {
  if((str.length() %2) == 1  ) return -1 ;

  stack<char> s ;
    for(int i =0 ;i < str.length() ;i ++ ) {
      char c= str[i] ;

      if(c== '{' ){
          s.push(c) ;
      }
      else{
        if(!s.empty() && s.top() == '{' ){
          s.pop() ;
        }
        else {
          s.push(c) ;
        }
      }

    }


  int a = 0, b= 0 ; 
  while(!s.empty() ){
    if(s.top() == '{') {
      b++ ;
    }
    else {
      a++ ;
    }
    s.pop() ;
  }
int ans = (a+1)/2 + (b+1)/2;

return ans ;


}

int main(){

    string s1 = "{{{}" ;
    cout << findMinimumCost(s1) << endl;


    string s2 = "{{}{}}" ;
    cout << findMinimumCost(s2) << endl;

}