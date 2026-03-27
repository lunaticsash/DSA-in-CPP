#include<bits/stdc++.h>

using namespace std;

bool subsetSumtoKSpaceOptimization(int n, int k, vector<int> &arr)
{
    vector<bool> prev(k + 1, 0), cur(k + 1, 0);
    prev[0] = cur[0] = true;
    prev[arr[0]] = true;
    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target < k; target++)
        {
            bool notTake = prev[target];
            bool take = false;
            if (arr[ind] <= target)
                take = prev[target - arr[ind]];
            cur[target] = take || notTake;
        }
        prev = cur;
    }
    return prev[k];
}

bool canPartition(vector<int> &arr, int n){

    int totsum = 0;
    for (int i = 0; i < n; i++)
        totsum += arr[i];
    if (totsum % 2 != 0)
        return false;

    int target = totsum/2;
    return subsetSumtoKSpaceOptimization(n, target, arr);

}