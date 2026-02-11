#include <bits/stdc++.h> 
#include <vector>
using namespace std;

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector<int> ans;

    for( int col = 0; col < mCols ; col++){
        if(col&1){
            //Odd case -> Bottom to top
            for(int rows = nRows-1; rows>= 0; rows--){
                ans.push_back(arr[rows][col]);
            }
        }
        else{
            //Even case -> Top to Bottom
            for(int rows = 0; rows < nRows; rows++){
                ans.push_back(arr[rows][col]);
            }
        }
    }
    return ans;
}