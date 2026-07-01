#include <bits/stdc++.h>
using namespace std;



//Best Approach:
class Solution {
public:
    int beautySum(string s) {
        int beauty = 0;

        for (int i = 0; i < s.size(); i++) {
            vector<int> freq(26, 0);

            for (int j = i; j < s.size(); j++) {
                freq[s[j] - 'a']++;

                int mx = 0;
                int mn = INT_MAX;

                for (int k = 0; k < 26; k++) {
                    if (freq[k] == 0)
                        continue;

                    mx = max(mx, freq[k]);
                    mn = min(mn, freq[k]);
                }

                beauty += (mx - mn);
            }
        }

        return beauty;
    }
};

//Have to optimize tc
class Solution {
public:
    vector<string> findSubstrings(string &s) {
        vector<string> res;

        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {
                res.push_back(s.substr(i, j - i + 1));
            }
        }

        return res;
    }

    int beautySum(string s) {
        vector<string> ans = findSubstrings(s);

        int beauty = 0;

        for (string &str : ans) {

            // Beauty of length-1 substring is always 0
            if (str.length() == 1)
                continue;

            vector<int> freq(26, 0);

            // Count frequencies
            for (char ch : str)
                freq[ch - 'a']++;

            int mx = 0;
            int mn = INT_MAX;

            // Find maximum and minimum non-zero frequencies
            for (int i = 0; i < 26; i++) {
                if (freq[i] == 0)
                    continue;

                mx = max(mx, freq[i]);
                mn = min(mn, freq[i]);
            }

            beauty += (mx - mn);
        }

        return beauty;
    }
};