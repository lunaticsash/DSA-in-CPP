#include <bits/stdc++.h>
using namespace std;

// Group similar elements into buckets. Instead of Sorting Algorithm, we can use Bucket Sort to sort the elements in O(n) time complexity. It is a distribution sort algorithm that works by distributing the elements of an array into a number of buckets. Each bucket is then sorted individually, either using a different sorting algorithm or by recursively applying the bucket sort algorithm.

//TC = O(n)avg and O(n²) worst case

class Solution
{
    void bucketSort(vector<float> &arr)
    {
        int n = arr.size();

        vector<vector<float>> bucket(n);

        for (float x : arr)
        {
            int idx = n * x;

            bucket[idx].push_back(x);
        }

        for (auto &b : bucket)
            sort(b.begin(), b.end());

        int index = 0;

        for (auto &b : bucket)
        {
            for (float x : b)
            {
                arr[index++] = x;
            }
        }
    }
};

/*
Algorithm:
Create buckets

↓

Put each element into correct bucket

↓

Sort inside every bucket

↓

Traverse buckets


When to use
    Frequency problems

    Leetcode 451

    Top K Frequent Elements

    Grouping problems

Pros
    Linear average time
    Great for frequency
    Great when values are evenly distributed
Cons
    Needs good bucket distribution
    Worst case O(n²)
*/