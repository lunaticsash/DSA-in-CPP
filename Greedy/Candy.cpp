#include <bits/stdc++.h>
using namespace std;

//using slope method
//TC = O(n)
//SC = O(1)
class Solution {
public:
    int candy(vector<int>& rating) {
        int sum = 1, i = 1;

        int n = rating.size();

        while (i < n) {

            // flat
            if (i < n && rating[i] == rating[i - 1]) {
                sum++;
                i++;
                continue;
            }

            // Increasing slope
            int peak = 1;
            while (i < n && rating[i] > rating[i - 1]) {
                peak += 1;
                sum += peak;
                i++;
            }

            // Decreasing slope
            int down = 1;
            while (i < n && rating[i] < rating[i - 1]) {
                sum += down;
                i++;
                down++;
            }
            
            if (down > peak) {
                sum += down - peak;
            }
        }

        return sum;
    }
};

//TC = O(2n) = O(n)
//SC = O(n)
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n+1, 1);

        for(int i = 1; i < n ; i++){
            if(ratings[i] > ratings[i-1]){
                left[i] = left[i-1] + 1;
            }
        }

        int cur = 1, right = 1, sum = max(1,left[n-1]);
        for(int i = n-2; i >=0 ; i--){
            if(ratings[i] > ratings[i+1]){
                cur = right + 1;
                right = cur;
            }else
                cur = 1;

            sum = sum + max(left[i], cur);
        }
    
        return sum;
    }
};

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