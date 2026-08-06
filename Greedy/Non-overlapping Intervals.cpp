#include <bits/stdc++.h>
using namespace std;

// TC = O(nlogn) + O(n) = O(nlogn)
// SC = O(1)
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) { return a[1] < b[1]; }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);

        int count = 1;
        int lastOneWas = intervals[0][1];

        int n = intervals.size();

        for(int i = 1; i < n ; i++){
            if(lastOneWas <= intervals[i][0]){
                count++;
                lastOneWas = intervals[i][1];
            }
        }

        return n - count;
    }
};