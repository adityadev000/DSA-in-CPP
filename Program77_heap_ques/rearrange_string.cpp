//p77 -> q3 -> rearrange string 
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>

using namespace std;
string reArrangeString(string &s) 

{
    unordered_map<char, int> charFreq;
    priority_queue<pair<int, char>> maxHeap;
    // Count the frequency of each character

    for (char c : s) 
    {
        charFreq[c]++;
    }

    // Fill the max heap with characters and their frequencies
    for (auto it : charFreq) 
    {
        maxHeap.push({it.second, it.first});
    }
    string result = "";
    // Construct the new string
    while (!maxHeap.empty()) 
    {
        pair<int, char> first = maxHeap.top();
        maxHeap.pop();
        // If the result string is empty or the last appended character is different from the current character
        if (result.empty() || result.back() != first.second) 
        {
            result += first.second;
            if (--first.first > 0) 
            {
                maxHeap.push(first);
            }
        } 

        else
        {
            // If the last appended character is the same as the current character, get the next character from the heap
            if (maxHeap.empty()) 
            {
                // If the heap is empty and there is still a character left to append, it's not possible
                return "not possible";
            }
            pair<int, char> second = maxHeap.top();
            maxHeap.pop();
            result += second.second;
            if (--second.first > 0) 
            {
                maxHeap.push(second);
            }
            // Put back the first character back into the heap
            maxHeap.push(first);
        }
    }

    return result;
}

int main(){


    string ss= "ddapbb" ;
    string ans = reArrangeString(ss) ;
    cout << ans << endl;

}