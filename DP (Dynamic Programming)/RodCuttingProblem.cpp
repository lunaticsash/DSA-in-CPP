#include <bits/stdc++.h>
using namespace std;

// Recursion
// T.C = exponentional (o(2^n))
// S.C = O(n*n) + O(N);
int f1(int ind, int N, vector<int> &price)
{
    if (ind == 0)
        return N * price[0];

    int notTake = 0 + f1(ind - 1, N, price);
    int take = INT_MIN;
    int rodlength = ind + 1;
    if (N >= rodlength)
        take = price[ind] + f1(ind - 1, N - rodlength, price);

    return max(notTake, take);
}

int RodCuttingProblem1(vector<int> &price, int n)
{
    return f1(n - 1, n, price);
}

// Memoization
// T.C = O(n*n)
// S.C = O(n*n) + O(N);
int f2(int ind, int N, vector<int> &price, vector<vector<int>> &dp)
{
    if (ind == 0)
        return N * price[0];

    if (dp[ind][N] != -1)
        return dp[ind][N];

    int notTake = 0 + f2(ind - 1, N, price, dp);
    int take = INT_MIN;
    int rodlength = ind + 1;
    if (N >= rodlength)
        take = price[ind] + f2(ind - 1, N - rodlength, price, dp);

    return dp[ind][N] = max(notTake, take);
}

int RodCuttingProblem2(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return f2(n - 1, n, price, dp);
}

// Space optimize
// T.C = O(n*n)
// S.C = O(2n);
int RodCuttingProblem3(vector<int> &price, int n)
{
    vector<int> prev(n + 1, 0);
    vector<int> cur(n + 1, 0);
    for (int N = 0; N <= n; N++)
    {
        prev[N] = N * price[0];
    }
    for (int ind = 1; ind <= n - 1; ind++)
    {
        for (int N = 0; N <= n; N++)
        {
            int notTake = 0 + prev[N];
            int take = INT_MIN;
            int rodlength = ind + 1;
            if (N >= rodlength)
                take = price[ind] + prev[N - rodlength];

            cur[N] = max(notTake, take);
        }
        prev = cur;
    }
    return prev[n];
}


// Space optimize into 1D array
// T.C = O(n*n)
// S.C = O(n);
int RodCuttingProblem3(vector<int> &price, int n)
{
    vector<int> prev(n + 1, 0);
    for (int N = 0; N <= n; N++)
    {
        prev[N] = N * price[0];
    }
    for (int ind = 1; ind <= n - 1; ind++)
    {
        for (int N = 0; N <= n; N++)
        {
            int notTake = 0 + prev[N];
            int take = INT_MIN;
            int rodlength = ind + 1;
            if (N >= rodlength)
                take = price[ind] + prev[N - rodlength];

            prev[N] = max(notTake, take);
        }
    }
    return prev[n];
}