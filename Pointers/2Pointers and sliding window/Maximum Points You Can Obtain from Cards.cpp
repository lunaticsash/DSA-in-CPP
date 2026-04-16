#include<bits/stdc++.h>
using namespace std;

//TC => O(K)
//SC => O(1)
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lSum =0;
        int rSum = 0;
        int maxSum = 0;
        for(int i = 0; i < k; i++) lSum = lSum + cardPoints[i];

        maxSum = lSum;
        int rindex = cardPoints.size() - 1;

        for(int i = k-1; i>=0 ; i--){
            lSum = lSum - cardPoints[i];
            rSum =  rSum + cardPoints[rindex];
            rindex = rindex - 1;

            maxSum = max(maxSum, lSum + rSum);
        }
        return maxSum;
    }
};