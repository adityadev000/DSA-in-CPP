#include <iostream>
using namespace std;

int main() {

    int row;
    cin >> row;

    int col;
    cin >> col;

    //creating a 2D array
    int** arr = new int*[row];
    for(int i=0; i<row; i++) {
        arr[i] = new int[col];
    }

    //taking input
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            cin >> arr[i][j];
        }
    }

    //taking output
    cout << endl;
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            cout << arr[i][j] << " ";
        } cout << endl;
    }


    //releasing memory
    for(int i=0; i<row; i++) {
        delete [] arr[i];
    }   

    delete []arr;

    //how to create a 2D array dynamically
    //input/Output
    //memory free kaise karani hai 


 // JAGGED ARRAY ;

 /*
    int n = 3 ;
    int col[3] = {2,3,4} ;
    int ** arr = new int *[n] ;

    cout << "memeory allocation" << endl;
    for (int i = 0; i< n ;i ++ ){
        arr[i] = new int [col[i]] ;
    }
    cout << "cin start " << endl;
    for (int i = 0 ; i <n ; i++ ){
        for(int j = 0; j< col[i] ; j++){
            cin >> arr[i][j];
        }
    }
    cout << "printing jagged array " << endl;
    for (int i = 0 ; i <n ; i++ ){
        for(int j = 0; j< col[i] ; j++){
            cout <<  arr[i][j] << "  ";
        }
        cout  << endl;
    }




    
 */
    return 0;
}