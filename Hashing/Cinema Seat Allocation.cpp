#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        //Total number of seats possible

        long long count  = n*2;

        unordered_map<int, vector<int>> mp;

        //Filling map
        for( auto &seat : reservedSeats){
            int row = seat[0];
            int s = seat[1];

            //Seat 1 and 10 ka kaam hi nhi
            if(s==1 || s == 10){
                continue;
            }

            mp[row].push_back(s);
        }

        //Process only row having relevent reservations
        for(auto &[row, seats] : mp){
            bool left = true; //2,3,4,5
            bool right = true; //6,7,8,9
            bool middle= true; //4,5,6,7

            for(int s: seats){
                if(s >=2 && s <= 5){
                    left = false;
                }
                if(s >= 6 && s<=9){
                    right = false;
                }
                if(s>=4 && s<=7){
                    middle = false;
                }
            }

            // Left + Right don't overlap
            if(left && right){
                continue;
            }

            // At least one block is available
            if(left || middle || right ){
                count--;
            }
            else{
                // None is available
                count -= 2;
            }
        }

        return count;
    }
};