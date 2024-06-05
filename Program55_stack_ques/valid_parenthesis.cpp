//p55 -> q3 ->valid parenthesis
#include<iostream>
#include<stack>

using namespace std;


bool isValidParenthesis(string s)
{
    stack<char>st ;
    for(int i =0 ;i < s.length() ; i++ ){
        char c =s[i ] ;

        if(s[i] == '(' ||   s[i] == '{' ||       s[i] == '['    ) {
            st.push(c); 
        }

        else {
            if( !st.empty() ) {
            char topp = st.top();
                if( (s[i] == ')'  &&  topp == '('   ) ||   (s[i] == '}'   && topp == '{' )  ||      ( s[i] == ']' && topp== '['   )   ){
                    st.pop() ;
                }
                else 
                return false ;
            }
            else 
            return false ;
        }
    }
     if(st.empty()) return true ;
        else return false ; 
}  

int main(){

    string s1 = "{[()]}" ;
    cout << isValidParenthesis(s1) << endl;

    string s2 = "[{(}]" ;
    cout << isValidParenthesis(s2) << endl;


}