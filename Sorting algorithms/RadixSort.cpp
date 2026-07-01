// Sort one digit at a time.
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void countingSort(vector<int> &arr, int exp)
    {
        int n = arr.size();

        vector<int> output(n);

        vector<int> count(10, 0);

        for (int x : arr)
            count[(x / exp) % 10]++;

        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (int i = n - 1; i >= 0; i--)
        {
            int digit = (arr[i] / exp) % 10;

            output[count[digit] - 1] = arr[i];

            count[digit]--;
        }

        arr = output;
    }

    void radixSort(vector<int> &arr)
    {
        int mx = *max_element(arr.begin(), arr.end());

        for (int exp = 1; mx / exp > 0; exp *= 10)
            countingSort(arr, exp);
    }
};

/*
Algorithm:
1. Find the maximum element to determine the number of digits.
2. For each digit position, sort the elements using counting sort.
3. Repeat for all digit positions.

Time Complexity: O(d * n)
Space Complexity: O(n + k)

Pros
    Faster than comparison sorting for integers
    Stable
    Linear for fixed digits
Cons
    Works mainly for integers (or fixed-length keys)
    More memory
    Not comparison-based
*/