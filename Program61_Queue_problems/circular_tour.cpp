//p61 -> q5 -> circular tour.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};
int tour(petrolPump p[],int n)
{
   int deficit = 0;
   int balance = 0;
   int start = 0;
   
   for(int i=0; i<n; i++) {
       balance += p[i].petrol - p[i].distance;
       if(balance < 0) {
           start = i+1;
           deficit += balance;
           balance = 0;
       }
   }
   
   if(balance + deficit >=0) 
        return start;
    return -1;
   
}


int main(){

    petrolPump p[4];
    p[0].petrol = 4 ;
    p[0].distance = 6;

    p[1].petrol = 6;
    p[1].distance = 5;

    p[2].petrol = 7;
    p[2].distance = 3 ;
    
    p[2].petrol = 4;
    p[2].distance = 5;

    cout << tour(p, 4) << endl;


}