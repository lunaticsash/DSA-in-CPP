#include <iostream>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        int i = 0;
        int ansIndex = 0;
        int n = chars.size();
        while(i<n){
            int j = i + 1;
            while(j<n && chars[i]==chars[j]){
                j++;
            }
            //yaha kb aaoge?
            //ya to vector pura traverse kr diya
            //ya fir New/Different charachter encounter kia hai

            //old char store krlo

            chars[ansIndex++] = chars[i]

            int count = j - i;
            if(count> 1){
                //converting counting into single digit and saving in answer
                string cnt = to_string(count);//count ko string mai convert kr liya
                for(char ch : cnt){
                    chars[ansIndex++]= ch;
                }

            }
            i=j;


        }
    }
    return ansIndex;
};

int main(){
    string s;
    cin>>s;
}