// YOu are given a string S with length n, you should find a permutation P of numbers 1 through n such that if you apply this 
// permutation on the string S, you will get a palindromic string.

#include <bits/stdc++.h>
using namespace std;

char getChar(int i) {
    return 'a' + i;
}

// Example: For string "aabb", indexesMap will be {'a': [0,1], 'b': [2,3]}
// We place 'a' at start and end: ans[0] = 0, ans[3] = 1
// We place 'b' at start and end: ans[1] = 2, ans[2] = 3
// Resulting permutation: [1, 3, 4, 2] (1-based indexing)
void printPalindrome (string s) {
    map<char, vector<int>> indexesMap; // Stores the indexes of each character in the string, e.g., {'a': [0,1], 'b': [2,3]} for "aabb"
    // Fill the indexesMap with the positions of each character in the string
    // Example: For string "aabb", after this loop, indexesMap will be {'a': [0,1], 'b': [2,3]}
    for (int i =0; i< s.size(); i++) {
        indexesMap[s[i]].push_back(i);
    }

    // Count the number of characters with odd frequency
    // Example: For string "aabb", odd_frequency_count will be 0
    // Example: For string "aabc", odd_frequency_count will be 2
    int odd_frequency_count =0;
    for (auto &entry : indexesMap) {
        if (entry.second.size() % 2 != 0) {
            odd_frequency_count++;
        }
    }
    
    // If there is more than one character with odd frequency, it is impossible to form a palindrome
    // Example: For string "aabc", odd_frequency_count is 2, so we print "-1" and return
    if (odd_frequency_count > 1) {
        cout << "-1";
        return;
    }

    // Initialize the answer array with -1 to indicate unfilled positions
    // Example: For string "aabb", ans will be [-1, -1, -1, -1] initially
    int ans[s.length()];
    int start=0;
    int end= s.length() -1;

    // Fill the answer array with -1 to indicate unfilled positions
    // Example: For string "aabb", ans will be [-1, -1, -1, -1] initially
    for (int i = 0; i < s.length(); i++) {
        ans[i] = -1;
    }
    // Now we will fill the answer array with the positions of characters to form a palindrome
    // We iterate over each character from 'a' to 'z' and place them at the start and end of the array
    // If a character has an odd frequency, the last occurrence will be placed in the middle of the array
    for (int i=0;i < 26; i++){
        char currentChar = getChar(i);
        // Example: For currentChar 'a' with indexes [0,1], we will place 0 at start and 1 at end
        for (int j=0; j< indexesMap[currentChar].size(); j+=2) {
            // If there is only one occurrence left, place it in the middle
            if(indexesMap[currentChar].size() - j == 1) {
                ans[s.length()/2] = indexesMap[getChar(i)][j];
                continue;
            }
            // Place the current character at the start and end of the array
            // Example: For currentChar 'a' with indexes [0,1], we will place 0 at start and 1 at end
            ans[start++] = indexesMap[getChar(i)][j];
            ans[end--] = indexesMap[getChar(i)][j+1];
        }

    }

    // Print the final answer array which represents the positions of characters to form a palindrome
    // Example: For string "aabb", the output will be "1 2 4 3" (1-based indexing)
    for (int i =0; i< s.length(); i++) {
        cout << ans[i] + 1 << " ";
    }
}


int main() {
    int t;
    cin>>t;

    while(t--) {

        string s;
        cin>> s;

        printPalindrome(s);
        
        cout<< endl;
    }


    return 0;
}