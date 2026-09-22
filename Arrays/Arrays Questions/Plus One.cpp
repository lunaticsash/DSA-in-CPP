#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());

        int n = digits.size();
        int i = 0;
        int carry = 1;  // We are adding 1

        while (i < n && carry != 0) {
            if (digits[i] == 9) {
                digits[i] = 0;
                carry = 1;
            } 
            else {
                digits[i]++;
                carry = 0;
            }

            i++;
        }

        // If carry is still left, we need a new digit
        if (carry == 1) {
            digits.push_back(1);
        }

        reverse(digits.begin(), digits.end());

        return digits;
    }
};