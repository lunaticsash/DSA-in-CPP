#include <bits/stdc++.h>
using namespace std;

//TC = O(3n) = O(n)
//SC = O(2n) = O(n)
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        vector<int> left(n, 1);
        vector<int> right(n, 1);

        // Give candies based on left neighbour
        for(int i = 1; i < n; i++) {
            if(ratings[i] > ratings[i-1]) {
                left[i] = left[i-1] + 1;
            }
        }

        // Give candies based on right neighbour
        for(int i = n-2; i >= 0; i--) {
            if(ratings[i] > ratings[i+1]) {
                right[i] = right[i+1] + 1;
            }
        }

        int sum = 0;

        for(int i = 0; i < n; i++) {
            sum += max(left[i], right[i]);
        }

        return sum;
    }
};