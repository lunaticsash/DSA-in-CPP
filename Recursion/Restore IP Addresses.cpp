#include <bits/stdc++.h>
using namespace std;

// TC = O(1)
// SC = O(4)
class Solution {
public:

    bool isTrue(int index, int i , string s){
        //i-ind <=3 and 0<=s.str(index, i - index+1) <= 255 && if(index-i >1 then s[ind] !=0)

        if (i - index + 1 > 3) return false;

        if (index != i && s[index] == '0') {
            return false;
        }

        int num = stoi(s.substr(index, i - index + 1));

        return num >= 0 && num <= 255;
    }

    void solve(vector<string>& ans, vector<string>& path, string s,
                 int index , int pcount){
        //Base case 
        if (index == s.size() && pcount == 4) {
            string temp = path[0] + "." + path[1] + "." +
                          path[2] + "." + path[3];
            ans.push_back(temp);
            return;
        }

        if (pcount == 4 || index == s.size()) return;

        for(int i = index ; i < s.size(); i++){
            if(isTrue(index, i, s)){
                path.push_back(s.substr(index, i-index+1));
                solve(ans, path, s, i+1, pcount+1);
                //Backtrack
                path.pop_back();
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        vector<string> path;
        if (s.size() < 4 || s.size() > 12) return ans;

        solve(ans, path, s , 0,0);

        return ans;
    }
};