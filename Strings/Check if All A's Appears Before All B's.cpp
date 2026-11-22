#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkString(string s) {
        int flag = 0;
        for(auto it : s){
            if(it == 'b'){
                flag = 1;
            }else if( flag == 1 && it == 'a'){
                return false;
            }
        }
        return true;
    }
};