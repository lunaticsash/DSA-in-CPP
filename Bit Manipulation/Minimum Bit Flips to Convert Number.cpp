#include<iostream>
using namespace std;

class Solution {
private:
    int countOnes(int n)
    {
        int count = 0;

        while (n > 0)
        {
            if (n & 1)
                count++;

            n = n >> 1;
        }

        return count;
    }
public:
    int minBitFlips(int start, int goal) {
        int ans = start ^ goal;
        return countOnes(ans);
    }
};

// In c++ only
class Solution {
public:
    int minBitFlips(int start, int goal) {
        return __builtin_popcount(start ^ goal);
    }
};