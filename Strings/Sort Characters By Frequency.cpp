#include <bits/stdc++.h>
using namespace std;


//By using bucket sort and unordered_map
//TC = O(n) + O(n) + O(n) = O(n) .No sorting needed
class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> freq;

        // Count frequency
        for(char ch : s)
            freq[ch]++;

        int n = s.size();

        // bucket[i] stores all chars with frequency i
        vector<vector<char>> bucket(n + 1);

        for(auto it : freq)
            bucket[it.second].push_back(it.first);

        string ans = "";

        // Traverse from highest frequency
        for(int i = n; i >= 1; i--)
        {
            for(char ch : bucket[i])
            {
                ans.append(i, ch);
            }
        }

        return ans;
    }
};

class Solution {
public:
    string frequencySort(string s) {

        map<char,int> mp;

        for(char ch : s)
            mp[ch]++;

        vector<pair<char,int>> v;

        for(auto it : mp)
            v.push_back(it);

        sort(v.begin(), v.end(),
            [](pair<char,int> a, pair<char,int> b)
            {
                return a.second > b.second;
            });

        string ans = "";

        for(auto it : v)
            ans.append(it.second, it.first);

        return ans;
    }
};
/*
Whenever you hear:

"Sort a map by values"
"Sort frequencies"
"Sort by second element"

your brain should immediately think:
        map
        ↓
vector<pair<key,value>>
        ↓
       sort()
*/