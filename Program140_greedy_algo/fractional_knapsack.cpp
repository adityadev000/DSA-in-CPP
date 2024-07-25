//p140 -> q8 -> Fractional Knapsack.
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct Item {
    int value; // value of the item
    int weight; // weight of the item
};

    static bool cmp(pair<double, Item> a, pair<double, Item> b) {
        // compare two items based on their value-to-weight ratio
        return a.first > b.first;
    }

    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item arr[], int n) {
        // create a vector to store items with their value-to-weight ratio
        vector<pair<double, Item>> v;

        for (int i = 0; i < n; i++) {

            // calculate the value-to-weight ratio of each item
            double per_u_val = (1.0 * arr[i].value / arr[i].weight);

            v.push_back({per_u_val, arr[i]});

        }

        // sort the items based on their value-to-weight ratio in descending order
        sort(v.begin(), v.end(), cmp);

        double total_val = 0; // total value of the items in the knapsack

        for (int i = 0; i < n; i++) {

            // if the weight of the current item is more than the remaining weight in the knapsack
            if (v[i].second.weight > w) {

                // add the value of the fraction of the item that can fit in the knapsack
                total_val += w * v[i].first;

                w = 0; // knapsack is full

            } 
            else {

                // add the value of the entire item
                total_val += v[i].second.value;

                // subtract the weight of the item from the remaining weight in the knapsack
                w = w - v[i].second.weight;
            }

        }
        return total_val;
    }

int main() {
    int n = 3; 
    int w = 50; // capacity of the knapsack
    Item arr[n] = {{60, 10}, {100, 20}, {120, 30}}; // items with their values and weights

    double max_val = fractionalKnapsack(w, arr, n);

    cout << "Maximum total value in the knapsack: " << max_val << endl;

}


