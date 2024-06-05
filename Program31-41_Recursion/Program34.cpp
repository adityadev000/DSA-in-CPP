#include<iostream>
#include<bits/stdc++.h>

using namespace std;
//P34a
bool ispalindrome(string &s , int i , int j ){
	if(i > j){
		return true ;
	}
	if(s[i] != s[j] ){
		return 0 ;
	}
	else{
		return ispalindrome(s ,i+1 ,j -1) ;
	}
}

//P34b
void reverse (string& strr , int i , int j ){
	if(i > j){
		return ;
	}
	swap (strr[i] ,strr[j] );
		i++ ;
		j -- ;
		reverse (strr , i, j) ;
	
}

//P34c
int power (int a ,int b ){
    if(b ==0){
        return 1 ;
    }
    if(b==1)
    return a ;

    if(b%2 != 0 ){
        return a * power(a,b/2) *power(a,b/2) ;
    }
    else{

    return  power(a,b/2) * power(a,b/2);
    }
}


//P34d
void bubble(int * arr , int n ) {
    if (n == 0 || n == 1){
        return  ;
    }
    for(int i  = 0 ;i < (n -1 );i ++ ){
        if (arr[i] > arr[i+1] ){
            swap(arr[i] , arr[i+1]) ;
        } 
    }
    bubble(arr, n-1) ;
}

int main(){
    
//p34a
    string p = "abcba" ;
    cout << "ispalindrome= " << ispalindrome(p,0, p.length() -1) << endl;

//p34b
    string s= "abcde" ;
    reverse(s , 0 , s.length() -1) ;
    cout << s << endl;
//p34c
    cout << power(2,10) << endl;

//p34d
    int arr[5]  = {4,7,2,3,1} ;
    bubble(arr,5 ) ;

    for(int i = 0; i< 5 ; i++){
        cout << arr[i] << " ";
    }
    cout  << endl;


}