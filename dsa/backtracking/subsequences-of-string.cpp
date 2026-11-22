// Return sub-sequences of the given string. All the sub-sequences.

#include<bits/stdc++.h>
using namespace std;

// Function to print all sub-sequences of a given string.
void printSubsequences(string str, string ans = "") {
    // If the string is empty, print the accumulated answer and return.
    if (str.empty()) {
        cout << ans << endl;
        return;
    }
    
    // Include the first character in the subsequence.
    printSubsequences(str.substr(1), ans + str[0]);
   // Exclude the first character in the subsequence.
    printSubsequences(str.substr(1), ans);
}