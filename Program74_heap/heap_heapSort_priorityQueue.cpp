//into to heap and priority queue
#include<iostream>
#include<queue>
#include<bits/stdc++.h>

using namespace std;

class heap {
public :
    int arr[100] ;
    int size ;

    heap() {
        arr[0] = -1 ;
        size =0 ;
    }
    void insert (int val ){
        //insert at end.
        size ++ ;
        int index = size;
        arr[index] = val ;

        while(index >1 ){
            int parent = index /2 ;
            if(arr[parent] < arr[index ]){
                swap(arr[parent] , arr[index]) ;
                index = parent ;
            }
            else return ;
        }
    }

    void delete_from_heap(){
        if(size == 0 ){
            cout << "nothing to delete" << endl;
            return ;
        }
        arr[1] = arr[size] ;
        size -- ;

        int i =1 ;
        while(i < size ){
            int left = 2*i;
            int right = 2*i+1 ;

            if (left < size && arr[i] < arr[left] && arr[left] > arr[right]){
                swap(arr[i] , arr[left]) ;
                i= left ;
            }
            else if (right < size && arr[i] < arr[right] && arr[left] < arr[right]){
                swap(arr[i] , arr[right]) ;
                i= right ;
            }
            else return ;

        }
    }

    void print (){
        for(int i = 1; i<= size ; i++){
            cout << arr[i] << " ";
        }cout <<  endl;
    }

};

void heapify  (int arr[] , int n ,int i){
    int largest = i ;
    int left  =2 *i ;
    int right = left+1 ;

    if(left <= n && arr[largest] < arr[left]){
        largest = left  ;
    } 
    if(right <= n && arr[largest] < arr[right]){
        largest = right  ;
    } 
    if(largest != i ){
        swap(arr[largest] , arr[i] ) ;
        heapify(arr ,n ,largest) ;
    }
}

void heap_sort(int arr[] , int n ){
    int size = n ;
    while(size > 1) {
        swap(arr[size] ,arr[1]) ;
        size -- ;

        heapify(arr , size ,1 );
    }
}

int main(){

    heap h ;
    h.insert(60);
    h.insert(50);
    h.insert(40);
    h.insert(30);
    h.insert(20);
    h.insert(55);

    h.print() ;

    h.delete_from_heap();
    h.print() ;

    int arr[6] = {-1,54,53,55,52,50} ;
    int n =5 ; 
    for(int i =n/2 ;i > 0 ;i--) {
        heapify(arr ,n ,i) ;
    }

    cout << "printing array" << endl;
    for(int i =1 ;i<= n ;i ++ ){
        cout << arr[i] << " " ;
    }cout <<  endl;

    //heap sort 
    heap_sort(arr , n );
    cout << "printing array after sorting " << endl;
    for(int i =1 ;i<= n ;i ++ ){
        cout << arr[i] << " " ;
    }cout <<  endl;
    


cout << "\n\npriority queue" << endl;
    //max heap
    priority_queue<int> pq ;
    cout << "creating max heap" << endl;
    pq.push(4);
    pq.push(7);
    pq.push(2);
    pq.push(9);

    cout << "element at top = "<< pq.top() << endl;
    pq.pop();
    cout << "element at top = "<< pq.top() << endl;
    cout << "size= "<< pq.size() << endl;

    if(pq.empty()){
        cout << "pq is empty"  << endl;
    }
    else{
        cout << "not empty" << endl;
    }

    //min heap 
    priority_queue<int , vector<int> , greater<int> > minheap ;
    cout << "\n\ncreating min heap" << endl;
    pq.push(4);
    pq.push(7);
    pq.push(2);
    pq.push(9);

    cout << "element at top = "<< pq.top() << endl;
    pq.pop();
    cout << "element at top = "<< pq.top() << endl;
    cout << "size= "<< pq.size() << endl;

    if(pq.empty()){
        cout << "pq is empty"  << endl;
    }
    else{
        cout << "not empty" << endl;
    }


}