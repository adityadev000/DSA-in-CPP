//p140 -> q6 -> Minimum Cost of ropes.
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

long long minCost(long long arr[], long long n) {

    // Priority queue banao, array ke elements daalo
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    // Array ke sabhi elements ko priority queue mein daal do
    for (int i = 0; i < n; i++) {
        pq.push(arr[i]); 
    }

    long long ans = 0; 

    // Jab tak priority queue mein 1 se zyada elements hai
    while (pq.size() > 1) {
        long long a = pq.top(); // smallest element nikalo
        pq.pop();

        long long b = pq.top(); // next smallest element nikalo
        pq.pop();

        long long sum = a + b; // dono ko add karo
        ans += sum; // sum ko answer mein add karo

        pq.push(sum); // sum ko priority queue mein daal do
    }

    return ans; // minimum cost return karo
}

int main() {
    long long arr[] = {4, 3, 2, 6}; 
    long long n = sizeof(arr) / sizeof(arr[0]); 

    long long result = minCost(arr, n); 
    cout << "Minimum cost: " << result << endl;

}


