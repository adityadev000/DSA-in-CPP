#include<iostream>
using namespace std;

int main(){

//p3a -> pattern1.
    int n1 ;
    cout << "enter n1" << endl;
    cin >> n1;
    for(int i = 1; i<= n1 ; i++){
        for(int j = 1; j<= n1 ; j++){
            cout << j<<" ";
        }
        cout << endl;
    }
//p3b -> pattern2.
    int n2 ;
    cout << "enter n2" << endl;
    cin >> n2;
    for(int i = 1; i<= n2 ; i++){
        for(int j = 1; j<= n2 ; j++){
            cout << (n2*(i-1))+j<<" ";
        }
        cout << endl;
    }
//p3c -> pattern3.
    int n3;
    cout << "enter n3" << endl;
    cin>> n3 ;
    for(int i = 1; i<= n3 ; i++){
        for(int j = 1; j<= i ; j++){
            cout << "*" ;
        }
        cout  << endl;
    }
//p3d -> pattern4.
    int n4;
    cout << "enter n4" << endl;
    cin>> n4 ;
    for(int i = 1; i<= n4 ; i++){
        for(int j = 1; j<= i ; j++){
            cout << i <<" " ;
        }
        cout  << endl;
    }
//p3e -> pattern5.

    int n5;
    cout << "enter n5" << endl;
    cin>> n5 ;
    int count = 1;
    for(int i = 1; i<= n5 ; i++){
        for(int j = 1; j<= i ; j++){
            cout << count <<" " ;
            count ++;
        }
        cout  << endl;
    }
//p3f -> pattern6.
    int n6;
    cout << "enter n6" << endl;
    cin>> n6;
    for(int i = 1; i<= n6 ; i++){
        for(int j = i; j<= (2*i-1) ; j++){
            cout << j <<" " ;
        }
        cout  << endl;
    }
//p3g -> pattern7.
    int n7;
    cout << "enter n7" << endl;
    cin>> n7;
    for(int i = 1; i<= n7 ; i++){
        // for(int j = i; j>= 1 ; j--){
        //     cout << j <<" " ;
        // }
        for(int j = 1; j<=i  ; j++){
            cout << (i-j+1) <<" " ;
        }
        cout  << endl;
    }
//p3h -> pattern8.
    int n8;
    cout << "enter n8" << endl;
    cin>> n8;
    
    for(int i = 1; i<= n8 ; i++){
        for(int j = 1; j<= n8 ; j++){
            char ch8 = 'A' +(i-1);
            cout << ch8 <<" " ;
        }
        cout  << endl;
    }
//p3i -> pattern9.
    int n9;
    cout << "enter n9" << endl;
    cin>> n9;
    
    for(int i = 1; i<= n9 ; i++){
        for(int j = 0; j< n9 ; j++){
            char ch9 = 'A' +j;
            cout << ch9 <<" " ;
        }
        cout  << endl;
    }
//p3j -> pattern10.
    int n10;
    cout << "enter n10" << endl;
    cin>> n10;
    char ch10 = 'A'; 
    for(int i = 1; i<= n10 ; i++){
        for(int j = 0; j< n10 ; j++){
            cout << ch10 <<" " ;
            ch10 ++;
        }
        cout  << endl;
    }
//p3k -> pattern11.
    int n11;
    cout << "enter n11" << endl;
    cin>> n11;
    for(int i = 1; i<= n11 ; i++){
        for(int j = 1; j<= n11 ; j++){
            char ch11 = 'A'+(i+j-2);
            cout << ch11 <<" " ;
        }
        cout  << endl;
    }
//p3l -> pattern12.
    int n12;
    cout << "enter n12" << endl;
    cin>> n12;
    for(int i = 1; i<= n12 ; i++){
        for(int j = 1; j<= i ; j++){
            char ch12 = 'A'+(i-1);
            cout << ch12 <<" " ;
        }
        cout  << endl;
    }
//p3m -> pattern13.
    int n13;
    cout << "enter n13" << endl;
    cin>> n13;
    char ch13 = 'A';
    for(int i = 1; i<= n13 ; i++){
        for(int j = 1; j<= i ; j++){
            cout << ch13 <<" " ;
            ch13 ++;
        }
        cout  << endl;
    }
//p3n -> pattern14.
    int n14;
    cout << "enter n14" << endl;
    cin >> n14;
    for(int i = n14; i>= 1 ; i--){
        for(int j = 1; j<=  (n14-i+1) ; j++){
           char ch14 = 'A'+(i+j-2); 
           cout << ch14 <<" ";
        }
        cout  << endl;
    }
//p3o -> pattern15.
    int n15;
    cout << "enter n15" << endl;
    cin >> n15;

    for(int i = 1; i<= n15 ; i++){
        // for spaces
        for(int j = 1; j<= (n15-i) ; j++){
            cout << " " ;
        }
        // for stars
        for(int j = 1; j<= i ; j++){
            cout << "*" ;
        }
        cout  << endl;
    }
//p3p -> pattern16.
    int n16;
    cout << "enter n16" << endl;
    cin >> n16;
    for(int i = 1; i<= n16 ; i++){
        // for spaces
        for(int j = 1; j<= (i-1) ; j++){
            cout << "  " ;
        }
        // for stars
        for(int j = 1; j<=(n16-i+1)  ; j++){
            cout << "* " ;
        }
        cout  << endl;
    }
//p3q -> pattern17.
    int n17;
    cout << "enter n17" << endl;
    cin >> n17;
    for(int i = 1; i<= n17 ; i++){
        // for spaces
        for(int j = 1; j<= (n17-i) ; j++){
            cout << "  " ;
        }
        // for half number
        for(int j = 1; j<= i ; j++){
            cout << j<<" ";
        }
        //for rem numbers;
        for(int j = (i-1); j>0 ; j--){
                cout << j<<" " ;
        }
        
        cout  << endl;
    }
//p3r -> pattern18.
    int n18;
    cout << "enter n18" << endl;
    cin >> n18;
    for(int i = 1; i<= n18 ; i++){
        // for ist tri
        for(int j = 1; j<= (n18-i+1) ; j++){
            cout << j <<" ";
        }
        // for 2nd tri
        for(int j = 1; j<= (2*i-2) ; j++){
            cout << "* ";
        }
        //for rem numbers;
        for(int j = (n18-i+1); j>0 ; j--){
                cout << j <<" ";
        }
        
        cout  << endl;
    }

}
