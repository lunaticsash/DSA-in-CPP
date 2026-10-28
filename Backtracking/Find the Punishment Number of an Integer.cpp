#include <bits/stdc++.h>
using namespace std;

//TO string
class Solution {
public:
    bool backtrack(string& s, int target, int ind, int currentSum) {
        if (ind == s.length()) {
            return currentSum == target;
        }

        long long num = 0;

        for (int i = ind; i < s.length(); i++) {
            num = num * 10 + (s[i] - '0');

            if (currentSum + num > target) {
                break;
            }

            if (backtrack(s, target, i + 1, currentSum + num)) {
                return true;
            }
        }

        return false;
    }

    int punishmentNumber(int n) {
        int totalSum = 0;

        for (int i = 1; i <= n; i++) {
            long long sq = (long long)i * i;
            string s = to_string(sq);

            if (backtrack(s, i, 0, 0)) {
                totalSum += sq;
            }
        }

        return totalSum;
    }
};


//Without to string
class Solution {
public:
    bool backtrack(vector<int>& digits, int target, int ind, int currentSum) {
        if (ind == digits.size()) {
            return currentSum == target;
        }

        int num = 0;

        for (int i = ind; i < digits.size(); i++) {
            num = num * 10 + digits[i];

            if (currentSum + num > target) {
                break;
            }

            if (backtrack(digits, target, i + 1, currentSum + num)) {
                return true;
            }
        }

        return false;
    }

    int punishmentNumber(int n) {
        int totalSum = 0;

        for (int i = 1; i <= n; i++) {
            int sq = i * i;
            vector<int> digits;

            int x = sq;
            while (x > 0) {
                digits.push_back(x % 10);
                x /= 10;
            }

            reverse(digits.begin(), digits.end());

            if (backtrack(digits, i, 0, 0)) {
                totalSum += sq;
            }
        }

        return totalSum;
    }
};