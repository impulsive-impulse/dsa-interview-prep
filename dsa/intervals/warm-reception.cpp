// You will be given arrival time and departure time of various guests, you will have to return the max guests at any point of time. 

#include<bits/stdc++.h>
using namespace std;

int maxGuests(int arr[], int dep[], int n) {
    sort(arr, arr+n);
    sort(dep, dep +n);

    int i =1, j=0, curr = 1, maxGuests = 1;
    while (i< n && j < n) {
        if (arr[i] < dep[j]) {
            curr++;
            maxGuests = max(maxGuests, curr);
            i++;
        } else {
            curr--;
            j++;
        }
    }

    return maxGuests;
}   