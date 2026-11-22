// Given and integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n
#include<bits/stdc++.h>
using namespace std;

string keypad[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
void printKeypadCombinations(string str, string ans = "") {
    // If the input string is empty, print the accumulated answer and return.
    if (str.empty()) {
        cout << ans << endl;
        return;
    }
    
    // Get the first digit of the input string.
    int digit = str[0] - '0';
    
    // Iterate over all characters corresponding to the current digit.
    for (char ch : keypad[digit]) {
        printKeypadCombinations(str.substr(1), ans + ch);
    }
}

int main() {
    string input;
    cin >> input;
    printKeypadCombinations(input);
    return 0;
}