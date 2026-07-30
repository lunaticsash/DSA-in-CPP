#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if ((n % groupSize) != 0)
            return false;

        map<int, int> mp;

        for (int x : hand) {
            mp[x]++;
        }

        while (!mp.empty()) {
            int start = mp.begin()->first;

            for (int i = 0; i < groupSize; i++) {
                if (mp.find(start + i) == mp.end())
                    return false;

                mp[start + i]--;

                if (mp[start + i] == 0)
                    mp.erase(start + i);
            }
        }
        return true;
    }
};