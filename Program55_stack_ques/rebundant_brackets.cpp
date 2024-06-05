//p55 -> q7 ->  redundant_brackets
#include<iostream>
#include<stack>

using namespace std;

bool findRedundantBrackets(string &s)
{
    stack<char> st ;
    for(int i =0 ; i< s.length() ; i++ ){
        char ch = s[i] ;
        if(ch == '('  || ch == '+' || ch == '-' || ch== '*' || ch == '/' ) {
            st.push(ch) ;
        }
        else{
            if(ch == ')' ){
                bool useless  = true ;
                while(st.top() != '('    ){
                    char c= st.top() ;
                    if(c == '+' || c == '-' || c== '*' || c == '/'  ){
                        useless = false ;
                    }
                    st.pop() ;
                }
                if(useless == true)
                    return true;
                st.pop() ;
            }
        }
    }
   
 return false ;
}


int main(){

    string s= "(a+b)" ;
    cout << findRedundantBrackets(s) << endl;

    string s1 = "((a+b))" ;
    cout << findRedundantBrackets(s1) << endl;


}