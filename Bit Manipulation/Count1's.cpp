#include <iostream>
using namespace std;

class Solution
{
private:
    //Brian Kernighan's Algorithm : Jump directly to an ON bulb, switch it off, and repeat until no bulbs are left on.
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
private:
//Walk past every bulb, checking whether it's on or off.
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
    int minBitFlips(int start, int goal)
    {
        int ans = start ^ goal;
        return countOnes(ans);
    }

};