// Q: Hussian shows hasan a multiset of integers. In every move Hussain removes a max no from this multi-set and divides it by 2. If after dividing, the 
// no is still positive he re-inserts it back into the multi-set. Hussain asks hasan M questions, the ith questions will be denoted by Q[i] and Hasan
// must find the value of no Hussain will be dividing after Q[i] -1 moves.

#include<bits/stdc++.h>
using namespace std;

int main () {

    int n,m;
    cin>> n >>m;
    vector<int> input(n);

    for (int i =0; i<n; i++) {
        cin>>input[i];
    }

    sort(input.begin(), input.end());

    queue<long long> q;

    while(m--) {
        int current_m;
        cin>> current_m;


        int ans, iteration =0, iterator = n-1;
        for (; iteration < current_m; iteration ++) {
            if (q.empty() || input[iterator] > q.front()) {
                ans = input[iterator--];
            } else {
                ans = q.front();
                q.pop();
            }
            if (ans > 1) {
                q.push(ans / 2);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}