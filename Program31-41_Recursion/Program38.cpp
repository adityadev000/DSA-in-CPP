// Letter combination of a phone number
#include <iostream>
#include <bits/stdc++.h>

using namespace std;


    void solve (string digits,string output , int index , vector<string> &ans , string mapping[]){
        // base case 
        if(index >= digits.length()){
            ans.push_back(output) ;
            return ;
        }

        int number = digits[index] - '0' ;
        string value = mapping[number] ;

        for(int i= 0; i< value.length() ; i++ ){
            output.push_back(value[i]) ;
            solve(digits, output , index+1 ,ans , mapping);
            output.pop_back() ;
        }


    } 

    vector<string> letterCombinations(string digits) {
        vector <string> ans ; 
        string output ="" ;
        int index = 0 ;

        if(digits.length() == 0) return ans ; 

        string mapping[10] = {"","","abc","def","ghi", "jkl" ,"mno","pqrs","tuv","wxyz"};

        solve(digits, output , index ,ans , mapping);

        return ans  ;
    }

    int main()
    {

        string digit = "23";
        letterCombinations(digit) ;
        cout << "Alright!!!!!!!!!" << endl;

    }