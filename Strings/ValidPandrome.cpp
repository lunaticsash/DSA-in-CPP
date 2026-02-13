// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers. Given a string s, return true if it is a palindrome, or false otherwise.

#include <iostream>
using namespace std;

class Solution {
private:

    bool valid(char ch){
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')){
            return 1;
        }
        return 0;
    }

    char toLowerCase(char ch){
    if((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')){
        return ch;
    }
    else{
        char temp = ch  - 'A'+ 'a';
        return temp;
    }
}

   bool palindrome(string a){
          int st = 0;
          int e = a.length() - 1;
     while(st<=e){
        if(a[st] != a[e]){
            return 0;
        }
        else{
            st++;
            e--;
        }
    }
    return 1;
}     

public:
    bool isPalindrome(string s) {

        //faltu character htaye

        string temp = "";
        for(int j = 0; j < s.length() ; j++){
            if(valid(s[j])){
                temp.push_back(s[j]);
            }
        }

        //to lowercase
        for(int j = 0 ; j < temp.length() ; j++){
            temp[j] =  toLowerCase(temp[j]);
        }

        //checking palindrome
     return palindrome(temp);
      
    }
};