#include<iostream>
#include<vector>

using namespace std;

void moveZeroes(vector<int>& nums) {

        //SHIFTING ALL NO ZEROES ELEMNT TO THE LEFT
        int NONZERO = 0;
        for(int j = 0;j< nums.size(); j++){

            if( nums[j] != 0){
                swap(nums[j], nums[NONZERO]);
                NONZERO++;
            }
        }
        
    }