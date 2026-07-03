#include<iostream>
using namespace std;

class Solution {
private:
    int BrianKernighanAlgorithm(int n)
    {
        int count = 0;

        while (n > 0)
        {
            n = n & (n - 1);
            count++;
        }

        return count;
    }
public:
    int hammingDistance(int x, int y) {
        int ans = x ^ y;
        return BrianKernighanAlgorithm(ans);
    }
};