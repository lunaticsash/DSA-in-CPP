#include <bits/stdc++.h>
using namespace std;

//Time:  O(n)
// Space: O(1)
//Reduce every stone to x % 3. Count remainders 0,1,2. The 0s only affect turn parity, while 1 and 2 determine whether a player can avoid making the cumulative sum divisible by 3. This leads to separate conditions based on whether cnt[0] is even or odd.
class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0, 0, 0};

        // Count stones based on remainder when divided by 3
        for (int x : stones) {
            cnt[x % 3]++;
        }

        // Even number of 0-remainder stones
        if (cnt[0] % 2 == 0) {
            return cnt[1] > 0 && cnt[2] > 0;
        }

        // Odd number of 0-remainder stones
        return abs(cnt[1] - cnt[2]) > 2;
    }
};

/*
Game
 ↓
Losing condition involves sum % 3
 ↓
Only remainder matters
 ↓
Only 3 possible states: 0, 1, 2
 ↓
Count how many stones belong to each state
 ↓
Game-theory observation
 ↓
Simple O(n) counting
*/