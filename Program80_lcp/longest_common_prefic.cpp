//p80 -> q -> longest common prefix.
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

//soln with trie.
class TrieNode {
    public :
    char data;
    int child_count ;
    TrieNode * children[26] ;
    bool is_terminal ;

    TrieNode(char c ){
        this -> data = c ;
        for(int i = 0; i< 26 ; i++){
            children[i] = NULL ;
        }
        this -> is_terminal = false ;
        this -> child_count = 0 ; 
    }
};

class Trie {
public:
    TrieNode* root ;
    Trie(char ch ){
        root = new TrieNode(ch) ;
    }
    

    void insert_util(TrieNode* root , string word ){
        //base case 
        if(word.length() == 0 ){
            root -> is_terminal = true ;
            return ;
        }
        int index = word[0] - 'a' ;
        TrieNode * child ;
        //present 
        if(root -> children[index] != NULL ){
            child = root -> children[index] ;
        }
        //absent 
        else {
            child = new TrieNode(word[0]) ;
            root -> child_count += 1  ; 
            root -> children[index] = child ;
        }
        //recursive calls.
        insert_util(child, word.substr(1)) ;
    }
    void insert_word (string word) {
        insert_util(root , word) ;
    }


    void  find_ans(string s , string & ans ){
        for(int i =0 ;i< s.length() ; i++ ){
            char ch  = s[i] ;
            if(root -> child_count == 1 ){
                ans.push_back(ch) ;
                int index = ch - 'a' ;
                root = root -> children[index] ;
            }
            else{
                 break ;
            }
            if(root -> is_terminal){
                break ;
            }
        }
    }

};

string longestCommonPrefix_trie(vector<string> &arr, int n)
{
    // Write your code here
    Trie* t = new Trie('\0'); 
    for(int i =0 ;i < arr.size() ; i++){
        t->insert_word(arr[i]) ;
    }
    string ans = "" ;
    t->find_ans(arr[0] , ans) ;
    return ans ; 
}

//soln without trie.
string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    string ans = "";
    for(int i = 0;i < arr[0].length() ; i++ ){
        char ch = arr[0][i] ;

        bool matched = true ;

        for(int j = 1 ;j < n ; j++ ){
            if(arr[j].size()  < i || ch != arr[j][i]){
                matched= false ;
                break ;
            }
        }
        if(matched == false){
            break ;
        }
        else{
            ans.push_back(ch) ;
        }

    }
    return ans ; 
}

int main(){

    vector<string> arr = {"coding", "codezen", "codingninja", "coders"} ;
    cout << longestCommonPrefix(arr , 4 ) << endl;


    cout << longestCommonPrefix_trie(arr , 4 ) << endl;


}