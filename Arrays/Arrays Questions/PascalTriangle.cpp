#include <bits/stdc++.h>
using namespace std;

//TC = O(N^2) SC = O(N^2)
class Solution{

    vector<int> generateRow(int row){

        long long ans = 1;
        vector<int> ansRow;
        ansRow.push_back(ans);

        for(int col = 1; col < row ; col++){
            ans = ans * (row - col);
            ans = ans / col;
            ansRow.push_back(ans);
        }
        return ansRow;
    }

    vector<vector<int>> generate(int numRows) {
       vector<vector<int>> ans;

       for(int i = 1; i <= numRows; i++){
         ans.push_back(generateRow(i));
       }
       return ans;
    }
};

//TC = O(N^2) SC = O(N^2)
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.resize(numRows);

        for(int i = 0; i < numRows; i++){
            ans[i].push_back(1);
            for(int j = 1; j <= i ; j++){
                if(i==j) ans[i].push_back(1);
                else{
                    ans[i].push_back(ans[i-1][j-1] + ans[i-1][j]);
                }
            }
        }

        return ans;
    }
};