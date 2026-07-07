#include<iostream>
using namespace std;

class Solution {
public:
    long long sumAndMultiply(int n) {
        long long ans = 0;
        int place = 1;
        int sum = 0;

        while (n > 0) {
            int digit = n % 10;
            n /= 10;

            if (digit == 0)
                continue;
            
            sum +=digit;

            ans = digit * place + ans;
            place *= 10;
        }

        return (sum*ans);
    }
};