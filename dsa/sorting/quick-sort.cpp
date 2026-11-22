#include<bits/stdc++.h>
using namespace std;

int partitionArray(vector<int>&arr, int start, int end) {
    int pivot = arr[start];
    int count = 0;

    for (int i = start +1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }

    int pivotIndex = start + count;
    swap(arr[start], arr[pivotIndex]);

    int i = start + 1;
    int j = end;

    while ( i <= pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot && i <= pivotIndex)
            i++;
        while (arr[j] > pivot && j > pivotIndex)
            j--;
        if (i < pivotIndex && j > pivotIndex)
            swap(arr[i++], arr[j--]);
    }

    return pivotIndex;
    
}

void quickSort(vector<int>&arr, int start, int end) {
    if(start>= end)
        return;

    int pivotIndex = partitionArray(arr, start, end);
    quickSort(arr, start, pivotIndex -1);
    quickSort(arr, pivotIndex + 1, end);
}


int main() {

    return 0;
}