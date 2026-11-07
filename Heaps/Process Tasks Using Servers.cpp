#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<int, int> P;        // wt, idx
    typedef tuple<long, int, int> T; // fintime, wt, idx

    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        // 2 Min Heaps
        priority_queue<P, vector<P>, greater<P>> freeServer;
        priority_queue<T, vector<T>, greater<T>> busyServer;

        for (int i = 0; i < n; i++) {
            freeServer.push({servers[i], i});
        }

        vector<int> result(m);

        for (int i = 0; i < m; i++) {
            // Move busy servers to free servers if they are free by ith time

            while (!busyServer.empty() && get<0>(busyServer.top()) <= i) {
                auto [fintime, wt, idx] = busyServer.top();
                busyServer.pop();
                freeServer.push({wt, idx});
            }

            // Konse server ko task assign hoga
            if (freeServer.empty()) {
                auto [fintime, wt, idx] = busyServer.top();
                busyServer.pop();
                result[i] = idx;
                busyServer.push({fintime + tasks[i], wt, idx});
            } else { // Free server is not empty
                auto [wt, idx] = freeServer.top();
                freeServer.pop();
                result[i] = idx;
                busyServer.push({i + tasks[i], wt, idx});
            }
        }

        return result;
    }
};