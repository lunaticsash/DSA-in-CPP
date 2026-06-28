#include<iostream>
#include<string>
using namespace std;

class Solution1 {
public:
    string largestOddNumber(string num) {
        
        for(int i = num.length()-1; i>=0 ; i--){
            int digit  = num[i] - '0';
            if(digit % 2 != 0){//odd
                return num;
            }else{//even
                num.erase(i);
            }
        }
        return "";
    }
};

class Solution2 {
public:
    string largestOddNumber(string num) {
        string ans, temp = "";
        for(auto ch : num){
            int digit  = ch - '0';
            if(digit % 2 == 0){
                temp+= ch;
            }
            else{
                ans +=temp;
                ans += ch;
                temp="";
            }
        }
        return ans;
        
    }
};