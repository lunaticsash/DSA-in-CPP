#include<bits/stdc++.h>
using namespace std;

//TC => O(T log T) where T is the number of tasks
//SC => O(T) where T is the number of tasks
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for(char t : tasks) freq[t - 'A']++;

        priority_queue<int> pq;
        for(int f : freq) {
            if(f > 0) pq.push(f);
        }

        int time = 0;

        while(!pq.empty()) {
            vector<int> temp;
            int cycle = n + 1;

            while(cycle-- && !pq.empty()) {
                int top = pq.top(); pq.pop();
                if(top - 1 > 0) temp.push_back(top - 1);
                time++;
            }

            for(int t : temp) pq.push(t);

            if(pq.empty()) break;

            time += cycle + 1; // add idle time
        }

        return time;
    }
};