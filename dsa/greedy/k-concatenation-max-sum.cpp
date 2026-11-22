// Given an array A with size N and an integer K. 
// Let's define another array B with size N*K asthe array that's formed by concatenating K copies of array A.
// Find longest sum subarray of that array.

#include <bits/stdc++.h>
using namespace std;

long long kadane(const vector<int>& arr) {
    long long currSum = 0;
    long long maxSum = 0;

    for (int x: arr) {
        currSum = max(currSum + x, x);
        maxSum = max(maxSum, currSum);
    }

    return maxSum;
}

long long maxSubarraySum(const vector<int>& arr, int k) {
   long long kadneSum = kadane(arr);

   if (k == 1) {
    return kadneSum;
   }

   long long curr_prefix_Sum = 0, curr_suffix_sum = 0;
   long long max_prefix_sum = INT_MIN, max_suffix_Sum = INT_MIN;

   for (int x: arr) {
    curr_prefix_sum += x;
    max_prefix_sum = max(max_prefix_sum, curr_prefix_sum);
   }

   for (auto it = arr.rbegin(); it != arr.rend(); ++it) {
        curr_suffix_sum += *it;
        max_suffix_Sum = max(max_suffix_Sum, curr_suffix_sum);
   }

   // For k > 2, the best subarray can include a suffix of the first copy,
   // all middle copies, and a prefix of the last copy.
   return max(kadneSum, max_prefix_sum + max_suffix_Sum + (k > 2 ? (k - 2) * accumulate(arr.begin(), arr.end(), 0LL) : 0LL));
}

int main() {
    int n,k;
    cin>> n >> k;
    vector<int> arr(n);

    for (int& x : arr) {
        cin>> x;
    }

    cout<< maxSubarraySum(arr, k);

    return 0;
}