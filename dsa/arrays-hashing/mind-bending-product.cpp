// Question: You are given an array A of size N; you hav to construct a Product array P such that P is equal to the product of
// all elements of A except the element at the same index.

#include<bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin>>n;
    vector<int> input(n, 0), product(n, 1);

    for (int i =0; i< n;i ++) {
        cin>>input[i];
    }

    long long leftProduct= 1;

    for ( int i =0; i< n; i++) {
        product[i] = leftProduct;
        leftProduct *= input[i];
    }

    long long rightProduct = 1;

    for (int i = n-1; i>=0; i-- ) {
        product[i] = product[i] * rightProduct;
        rightProduct = rightProduct * input[i];
    }

    for (int i = 0; i < n; i++) {
        cout << product[i] << (i + 1 == n ? '\n' : ' ');
    }



    return 0;
}