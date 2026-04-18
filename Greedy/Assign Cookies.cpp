#include<bits/stdc++.h>
using namespace std;

//TC => O(NlogN + MlogN)
//SC => O(1)
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int j = 0, ans = 0;
        for (int i = 0; i < g.size(); i++) {
            if (j == s.size())
                break;
            if (g[i] <= s[j]) {
                ans++;
                j++;
            } else if (g[i] > s[j]) {
                j++;
                i--;
            }
        }
        return ans;
    }
};

//Approach-2
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count = 0;
        int n = g.size();
        int m = s.size();

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int j = 0;
        for (int i = 0; i < n; i++) {
            for (; j < m; j++) {
                if (s[j] >= g[i]) {
                    count++;
                    j++;
                    break;
                }
            }
        }

        return count;
    }
};