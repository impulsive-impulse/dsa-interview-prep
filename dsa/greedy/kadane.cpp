// Kadane's algorithm - Given an integer array arr[], find the subarray (containing at least one element) which has the maximum possible sum, 
// and return that sum. A subarray is a continuous part of an array.
#include <bits/stdc++.h>
using namespace std;

long long kadane (const vector<int>& arr) {
    long long currSum = 0;
    long long maxSum =  0;

    for (long long x : arr) {
        currSum = max(x, currSum + x); // Start a new subarray at x or extend the current one.
        maxSum = max(maxSum, currSum);
    }

    return maxSum;
}

int main() {

    int n; 
    cin>> n;

    vector<int> arr(n);

    cout<<kadane(arr);

    return 0;
}
