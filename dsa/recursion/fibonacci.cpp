#include<bits/stdc++.h>
using namespace std;

// Recursive approach
long long fibonacci(int n) {
    if (n <= 1) {
        return n;
    }

    return 1LL*(fibonacci(n - 1) + fibonacci(n - 2)); // 1LL -> promotes the sum to long long to avoid int overflow.

}

int main() {
    int n;
    cin >> n;

    cout<< fibonacci(n);

    return 0;
}