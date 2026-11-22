// Given an array that contains both positive and negative integers, find the maximum product subarray.
// Example: 6, -3, -10, 0, 2 -> 180

#include<bits/stdc++.h>
using namespace std;

long long maxSubArrayProduct(const vector<int> &arr) {
    // An empty array has no non-empty subarray, so use 0 as the result.
    if (arr.empty()) {
        return 0;
    }

    // maxEnding is the largest product of a subarray ending at the current index.
    long long maxEnding = arr[0];
    // minEnding is the smallest product of a subarray ending at the current index.
    // Keeping the minimum is necessary because multiplying it by a negative value
    // can produce the largest product at the next index.
    long long minEnding = arr[0];
    // Initialize the best product seen so far with the first element.
    long long maxProduct = arr[0];

    // Process each remaining element, keeping subarrays contiguous.
    for (size_t i = 1; i < arr.size(); ++i) {
        // Convert to long long before multiplication to avoid int overflow.
        long long x = arr[i];
        // The largest product ending here either starts at x or extends
        // the previous maximum or minimum product.
        long long nextMax = max({x, maxEnding * x, minEnding * x});
        // The smallest product ending here is needed for a possible
        // negative multiplication at the next index.
        long long nextMin = min({x, maxEnding * x, minEnding * x});
        // Update both states only after computing them from the previous index.
        maxEnding = nextMax;
        minEnding = nextMin;
        // Record the best product seen at any index.
        maxProduct = max(maxProduct, maxEnding);
    }

    return maxProduct;
}

long long maxSubArrayProduct2(const vector<int> &arr) {
    int max_ending_here = 1;
    int min_ending_here = 1;
    int max_so_far = 0;

    for ( int i =0; i< arr.size(); i++) {
        if(arr[i] > 0) {
            max_ending_here = max_ending_here * arr[i];
            min_ending_here = min_ending_here * arr[i];
        } else if( arr[i] == 0) {
            max_ending_here = 1;
            min_ending_here = 0;
        } else {
            long long temp = max_ending_here;
            max_ending_here = max(min_ending_here * arr[i], 1);
            min_ending_here = temp * arr[i];
        }
        max_so_far = max(max_so_far, max_ending_here);
    }
    return max_so_far;
}

int main() {

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& x : arr) {
        cin >> x;
    }

    cout << maxSubArrayProduct(arr);

    return 0;
}