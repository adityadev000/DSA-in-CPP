#include <iostream>
using namespace std;

void printArray(int array[], int size)
{
    cout << "Printing the array" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}
//p9a -> Array maximum
int arymax(int arry[], int size)
{
    int maxi = INT32_MIN;
    for (int i = 0; i < size; i++)
    {
        maxi = max(maxi, arry[i]);

        // if(num[i] < min){
        //     min = num[i];
        // }
    }
    return maxi;
}
//p9b -> Array Minimum
int arymin(int arry[], int size)
{
    int mini = INT32_MAX;
    for (int i = 0; i < size; i++)
    {
        mini = min(mini, arry[i]);
    }
    return mini;
}
//p9c -> Array scope
void update(int array[], int size) {

    cout << endl << "Inside the function" <<endl;
    
    //updating array's first element
    array[0] = 120;

    //printing the array
    for(int i=0; i<size; i++) {
        cout << array[i] <<" ";
    } cout<<endl;


    cout << "Going back to main function" << endl;
}
//p9d -> Linear search
bool linearSearch (int arry[] , int size , int key){

    for(int i = 0; i< size ; i++){
        if(arry[i] == key ){
            return 1 ;
        }
    }

    return 0;

}
//p9e -> Reverse array
void reverseArray(int arry[], int size){
    int start = 0, end = (size -1);
   while(start <= end){
            swap (arry [start] , arry [end]);
            start ++ ;
            end -- ;
        }
    printArray ( arry ,size);
    }



//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
int main()
{
//ARRAY MAXIMUM AND MINIMUM
    int arr[10] = {3, 6, 7, 8, -12, 56, -3, -23, 5, 8};
    printArray(arr, 10);
    cout << "Maximum value is " << arymax(arr, 10) << endl;
    cout << "Minimum value is " << arymin(arr, 10) << endl;

//ARRAY SCOPE ;
    update(arr, 10);
    //printing the array
    cout<< endl << "Printing in main function" << endl;
    for(int i=0; i<10; i++) {
        cout << arr[i] <<" ";
    }
    cout  << endl;

//LINEAR SAERCH;
    bool found = linearSearch(arr, 10 ,5);
    cout  << endl;

    if (found ){
        cout << "Key is present" << endl;
    }
    else {
        cout << "Key is absent" << endl;
    }
    cout << endl;

// REVERSE ARRAY
    reverseArray( arr , 10); 




}