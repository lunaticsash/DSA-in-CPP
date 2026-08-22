#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int product = 1;

        int temp = n;

        int digit = 0;
        while(n > 0){
            digit = n %10; //9
            n = n /10; //0

            sum += digit;
            product *= digit; 
        }

        int to = sum + product;

        if(temp % to == 0)
            return true;

        return false;
    }
};