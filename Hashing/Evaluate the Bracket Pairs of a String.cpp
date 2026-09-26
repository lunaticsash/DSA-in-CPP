#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.length();
        int m = knowledge.size();
        int i = 0;
        string ans = "";
        unordered_map<string, string> mp;

        for (auto it : knowledge) {
            mp[it[0]] = it[1];
        }

        while (i < n) {        // O(n)
            if (s[i] != '(') { // not equal to (
                ans.push_back(s[i]);
                i++;
            } else { // Is equal to "("
                int j = i + 1;
                string word = "";
                while (s[j] != ')') {
                    word.push_back(s[j]);
                    j++;
                }

                // Search in knowledge
                if (mp.count(word)) {
                    ans += mp[word];
                } else {
                    ans += "?";
                }

                i = j + 1;
            }
        }

        return ans;
    }
};