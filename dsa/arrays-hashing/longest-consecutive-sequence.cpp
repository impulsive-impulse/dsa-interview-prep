// Given an array of integers, find the length of the longest sub-sequence such that elements in the sub-sequece are consecutive integers,
// the consecutive numbers can be in any order. 

#include<bits/stdc++.h>
using namespace std;

vector<int> LongestSubSequence(vector<int>& nums) {
    unordered_set<int> numSet(nums.begin(), nums.end());
    vector<int> longestSeq;
    int maxLength = 0;
    
    for (int num : nums) {
        if (!numSet.count(num - 1)) {
            int currentNum = num;
            vector<int> currentSeq;
            while (numSet.count(currentNum)) {
                currentSeq.push_back(currentNum);
                currentNum++;
            }
            if (currentSeq.size() > maxLength) {
                maxLength = currentSeq.size();
                longestSeq = currentSeq;
            }
        }
    }
    return longestSeq;
}