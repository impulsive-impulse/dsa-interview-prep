// Given a sequence of integers, the total variation count is the number of pairs of elements in the sequence with
// variation atleast k.
// Sample: 3 2 4; k=1
// Ans = 3 [(3,2), (3,4), (2,4)]

#include<bits/stdc++.h>
using namespace std;

int solve (vector<int> &arr, int k) {
    int ans = 0;
    sort(arr.begin(), arr.end());

    int i =0, j=1, n = arr.size();

    while(j< n) {
        if (arr[j] - arr[i] >= k){
            ans += n-j;
            i++; 
        } else{
            j++;
        }

    }
    
    return ans;
}

int main() {

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i =0;i <n ; i++) {
        cin >>arr[i];
    }

    int ans = solve(arr, k);

    cout << ans << endl;
    return 0;
}