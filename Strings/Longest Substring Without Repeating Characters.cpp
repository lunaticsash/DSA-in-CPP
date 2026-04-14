#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxi = 0;

        for(int i = 0; i < n; i++) {
            unordered_set<char> st;

            for(int j = i; j < n; j++) {
                // if duplicate found → break
                if(st.find(s[j]) != st.end()) {
                    break;
                }

                // insert character
                st.insert(s[j]);

                // update max length
                maxi = max(maxi, j - i + 1);
            }
        }

        return maxi;
    }
};
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_set<char> st;

        int left = 0;
        int maxi = 0;

        for(int right = 0; right < n; right++) {

            // if duplicate → shrink window
            while(st.find(s[right]) != st.end()) {
                st.erase(s[left]);
                left++;
            }

            // add current character
            st.insert(s[right]);

            // update max length
            maxi = max(maxi, right - left + 1);
        }

        return maxi;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int res=0;
        int i,j;
        i=0;j=0;
        int mp[256]={0};
        while (j<s.size())
        {
            if (mp[s[j]]==0)
            {
                mp[s[j]]++;
                j++;
            }
            else
            {
                mp[s[i]]--;
                i++;
            }

            if (j-i>res)
                res=j-i;
        }

        return res;
    }
};