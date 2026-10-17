#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans = "";
        int cnt[3] = {a, b, c};
        char ch[3] = {'a', 'b', 'c'};

        while (true) {
            int mx = -1, idx = -1;

            for (int i = 0; i < 3; i++) {
                if (cnt[i] > mx &&
                    !(ans.size() >= 2 &&
                      ans.back() == ch[i] &&
                      ans[ans.size()-2] == ch[i])) {
                    mx = cnt[i];
                    idx = i;
                }
            }

            if (idx == -1 || mx == 0) break;

            ans += ch[idx];
            cnt[idx]--;
        }

        return ans;
    }
};

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;

        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        string ans = "";

        while (!pq.empty()) {
            auto [cnt, ch] = pq.top();
            pq.pop();

            int n = ans.size();

            if (n >= 2 && ans[n-1] == ch && ans[n-2] == ch) {
                if (pq.empty()) break;

                auto [cnt2, ch2] = pq.top();
                pq.pop();

                ans += ch2;
                cnt2--;

                if (cnt2 > 0) pq.push({cnt2, ch2});
                pq.push({cnt, ch});
            }
            else {
                ans += ch;
                cnt--;

                if (cnt > 0) pq.push({cnt, ch});
            }
        }

        return ans;
    }
};