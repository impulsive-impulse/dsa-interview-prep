// You will be given intervlals like [L1, R1), [L12 R2) ..... [Ln, Rn). Then you will be given input integers and you have to print what's the
// next closest interval it is to.

#include<bits/stdc++.h>
using namespace std;

void solve(vector<pair<int,int>> &intervals, vector<int> &queries) {
    for(int q : queries) {
        pair<int,int> closest = {-1, -1};
        int minDist = INT_MAX;
        for(auto &interval : intervals) {
            if(q < interval.first) {
                int dist = interval.first - q;
                if(dist < minDist) {
                    minDist = dist;
                    closest = interval;
                }
            } else if(q >= interval.first && q < interval.second) {
                closest = interval;
                break;
            }
        }
        if(closest.first != -1) {
            cout << "[" << closest.first << ", " << closest.second << ")" << endl;
        } else {
            cout << "No closest interval" << endl;
        }
    }
}

void solveWithLowerbound(vector<pair<int,int>> &intervals, vector<int> &queries) {
    sort(intervals.begin(), intervals.end());
    for(int q : queries) {
        auto it = lower_bound(intervals.begin(), intervals.end(), make_pair(q, INT_MIN));
        if(it != intervals.end() && q >= it->first && q < it->second) {
            cout << "[" << it->first << ", " << it->second << ")" << endl;
        } else if(it != intervals.end()) {
            cout << "[" << it->first << ", " << it->second << ")" << endl;
        } else {
            cout << "No closest interval" << endl;
        }
    }
}


int main () {
    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> intervals(n);
    for(int i = 0; i < n; i++) {
        cin >> intervals[i].first >> intervals[i].second;
    }

    vector<int> queries(m);
    for(int i = 0; i < m; i++) {
        cin >> queries[i];
    }

    solve(intervals, queries);
    // solveWithLowerbound(intervals, queries); // Uncomment this line to use the lower_bound approach
    

    return 0;
}