#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//TC = O(n) and SC = O(1)
class Solution {
public:
    int maxProduct(int n) {
        int largest = -1, secondLargest = -1;

        while (n > 0) {
            int digit = n % 10;
            n /= 10;

            if (digit > largest) {
                secondLargest = largest;
                largest = digit;
            } 
            else if (digit > secondLargest) {
                secondLargest = digit;
            }
        }

        return largest * secondLargest;
    }
};


//TC = O(nlogn) and SC = O(n)
class Solution {
public:
    int maxProduct(int n) {
        vector<int> arr;
        while( n > 0){
        int digit = n % 10;
        n = n/10;
        arr.push_back(digit);
        }
        int o = arr.size() - 1;
        sort(arr.begin(), arr.end());

        return arr[o-1] * arr[o];
    }
};