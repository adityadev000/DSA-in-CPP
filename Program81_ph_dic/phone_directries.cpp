//p81 -> q ->  Implement a phone directory.
#include<iostream>
#include<bits/stdc++.h>

using namespace std;


class TrieNode {
    public :
    char data;
    TrieNode * children[26] ;
    bool is_terminal ;

    TrieNode(char c ){
        this -> data = c ;
        for(int i = 0; i< 26 ; i++){
            children[i] = NULL ;
        }
        this -> is_terminal = false ;
    }
};

class Trie {
public:
    TrieNode* root ;
    Trie(){
        root = new TrieNode('\0') ;
    }
    

    void insert_util(TrieNode* root , string word ){
        //base case 
        if(word.length() == 0 ){
            root -> is_terminal = true ;
            return ;
        }
        int index = word[0] - 'a' ;//assume all letters of word are in CAPS.
        TrieNode * child ;
        //present 
        if(root -> children[index] != NULL ){
            child = root -> children[index] ;
        }
        //absent 
        else {
            child = new TrieNode(word[0]) ;
            root -> children[index] = child ;
        }
        //recursive calls.
        insert_util(child, word.substr(1)) ;
    }
    void insert_word (string word) {
        insert_util(root , word) ;
    }

    void  print_sugg(TrieNode* curr , vector<string>& temp , string prefix){
        if(curr -> is_terminal){
            temp.push_back(prefix) ;
            //no return because this is not last word 
            //iske baad v to bahut word pichhe jake pint krna h.
        }

        for(char ch = 'a' ; ch <= 'z' ; ch ++ ){
            TrieNode* next = curr-> children[ch-'a'] ;

            if(next != NULL){
                prefix.push_back(ch) ;

                print_sugg(next , temp , prefix) ;
                prefix.pop_back() ;
            }
        }
    }

    vector<vector<string>> getsugg(string str){
        TrieNode* prev = root ;
        vector<vector<string>> output ; //for final ans.
        string prefix = "" ; //ek ek krke word dalenge

        for(int i =0 ; i< str.length() ; i++ ){
            char last_char = str[i] ;
            prefix.push_back(last_char) ;

            TrieNode* curr = prev-> children[last_char-'a'] ;

            if(curr == NULL){
                break ;
            }
            vector<string> temp ; //curr prefix k lye sarre suggetion isi me dalebge 

            print_sugg(curr , temp , prefix);

            output.push_back(temp ); 
            temp.clear() ;
            prev = curr ; 
        }
        return output ;
    }

};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    //    Write your code here.
    Trie* t = new Trie() ;

    //insert all string into trie ;
    for(int i =0 ;i< contactList.size() ; i++ ){
        t-> insert_word(contactList[i]) ;
    }

    return t->getsugg(queryStr) ;
}

int main(){

    vector<string> c =  {"cod" "coding" "codding" "code" "coly"} ; 
    string s= "coly" ; 
    vector<vector<string>> ans = phoneDirectory(c , s );

    for(int i = 0; i< ans.size() ; i++){
        for(int j = 0; j< ans[i].size() ; j++){
            cout << ans[i][j] << "\t";
        }
        cout  << endl;
    }
}