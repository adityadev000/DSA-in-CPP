//p79 -> trie implementation . 
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
    ~TrieNode(){
        char c = this -> data ;
        cout << "free memory "<< c << endl;
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
        int index = word[0] - 'A' ;//assume all letters of word are in CAPS.
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



    bool search_util(TrieNode* root , string word ){
        //base case 
        if(word.length() == 0 ){
            return root -> is_terminal;
        }

        int index = word[0] - 'A' ;//assume all letters of word are in CAPS.
        TrieNode * child ;
        //present 
        if(root -> children[index] != NULL ){
            child = root -> children[index] ;
        }
        //absent 
        else {
            return false ;
        }
        //recursive calls.
        return search_util(child, word.substr(1)) ;
    }
    
    bool search_word(string word ){
        return search_util(root , word ) ;
    }

//     void delete_util(TrieNode* root , string word) {
//             if(word.length() == 0){
//                 root -> is_terminal = false ;
//                 bool del = true ;
//                 for(int i = 0 ; i< 26 ; i++){
//                     if(root -> children[i] != NULL ){
//                         del = false ;
//                     }
//                 }
//                 if(del) {
//                     delete root ;
//                 }
//                 return;
//             }
//             int index = word[0] - 'A' ;
//             TrieNode* child = root -> children[index] ;
//             delete_util(child , word.substr(1)) ;
//             bool del = true ;
//             for(int i = 0 ; i< 26 ; i++){
//                 if(root -> children[i] != NULL ){
// // cout << "root = "<< root ->data  << endl;
// // cout << "present = "<< root -> children[i] ->data << endl;
//                     del = false ;
//                 }
//             }
//             if(del) {
//                 delete root ;
//             }
//     }
//     void delete_word(string word ){
//         delete_util(root , word); 
        
//     }
};


int main(){

    Trie* t = new Trie() ;
    //all letters are in CAPS
    t->insert_word("ABCD");
    t->insert_word("HELLO");
    t->insert_word("TIMER");
    t->insert_word("BABBAR");

    cout << "present or not =  "<< t-> search_word("ABCD") << endl;

    // t->delete_word("ABCD") ;
    // cout << "present or not =  "<< t-> search_word("ABCD") << endl;

}