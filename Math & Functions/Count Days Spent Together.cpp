#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int days(string date) { // MM-DD
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));

        int ans = day;

        for(int i = 0; i < month - 1; i++) {
            ans += arr[i];
        }

        return ans;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {

        int arriveAliceday = days(arriveAlice);
        int leaveAliceday = days(leaveAlice);
        int arriveBobday = days(arriveBob);
        int leaveBobday = days(leaveBob);

        int start = max(arriveAliceday, arriveBobday);
        int end = min(leaveAliceday, leaveBobday);

        if(start > end) return 0;

        return end - start + 1;
    }
};