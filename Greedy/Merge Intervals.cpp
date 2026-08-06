#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Step 1: Sort intervals by starting time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        // Step 2: Start with the first interval
        int start = intervals[0][0];
        int end = intervals[0][1];

        // Step 3: Process the remaining intervals
        for (int i = 1; i < intervals.size(); i++) {
            // If current interval overlaps with the next one
            if (intervals[i][0] <= end) {
                end = max(end, intervals[i][1]);
            } 
            // No overlap
            else {
                ans.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        // Step 4: Push the last merged interval
        ans.push_back({start, end});

        return ans;
    }
};