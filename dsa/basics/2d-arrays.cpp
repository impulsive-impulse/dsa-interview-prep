#include<bits/stdc++.h>
using namespace std;

int main() {

    // Dynamically allocated 2D array
    int rows, cols;
    cin >> rows >> cols;

    int **arr = new int*[rows]; // Allocate an array of row pointers.
    for(int i =0; i< rows; i++) {
        arr[i] = new int[cols]; // Allocate an array of integers for row i.
    }

    for( int i=0; i< rows; i++) {
        delete[] arr[i]; // Free the memory allocated for row i.
    }

    delete[] arr; // Free the memory allocated for the array of row pointers.


    // Using vectors
    vector<vector<int>> v(rows, vector<int>(cols));

}