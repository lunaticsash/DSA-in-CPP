// Instead of comparing elements, count how many times each value appears.
#include <bits/stdc++.h>
using namespace std;

//TC = O(n + k)
//SC = O(k) where k is the range of input
class Solution
{
public:
    void countingSort(vector<int> &arr)
    {
        int mx = *max_element(arr.begin(), arr.end());

        vector<int> count(mx + 1, 0);

        for (int x : arr)
            count[x]++;

        int index = 0;

        for (int i = 0; i <= mx; i++)
        {
            while (count[i]--)
            {
                arr[index++] = i;
            }
        }
    }
};

/*
Algotrithm:
1. Find maximum element.

2. Create count[max+1].

3. Count every number.

4. Traverse count array.

5. Print/store every value count[i] times.


When to use

✅ Small range

Marks (0-100)

Age (0-120)

Digits

Characters

Frequency arrays
*/