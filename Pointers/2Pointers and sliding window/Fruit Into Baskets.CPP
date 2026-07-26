#include<bits/stdc++.h>
using namespace std;

//TC = O(N) and SC = O(1)
class Solution{
  public:
    int totalFruits(vector<int>& fruits){
        int n = fruits.size();
        int l = 0, r= 0;
        unordered_map<int,int> mp;
        int maxlen = 0;

        while(r < n){
            mp[fruits[r]]++;
            if(mp.size() > 2){
                mp[fruits[l]]--;
                if(mp[fruits[l]] == 0){
                    mp.erase(fruits[l]);
                }
                l++;
            }
            if(mp.size() <= 2) maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
    }
};

//TC = O(2N) and SC = O(1)
class Solution{
  public:
    int totalFruits(vector<int>& fruits){
        int n = fruits.size();
        int l = 0, r= 0;
        unordered_map<int,int> mp;
        int maxlen = 0;

        while(r < n){
            mp[fruits[r]]++;
            while(mp.size() > 2){
                mp[fruits[l]]--;
                if(mp[fruits[l]] == 0){
                    mp.erase(fruits[l]);
                }
                l++;
            }
            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
    }
};
