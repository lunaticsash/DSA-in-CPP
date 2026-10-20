#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;
    ll MOD = 1e9 + 7;

    //Pascal triangle
    vector<vector<ll>> PT;

    int solve(vector<int> &nums){
        int n = nums.size();

        if(n<3) return 1;
        //n==1, n==2

        vector<int> left_array, right_array;

        int root = nums[0];

        for(int i = 1; i < n; i++){
            if(nums[i] < root){
                left_array.push_back(nums[i]);
            }else{
                right_array.push_back(nums[i]);
            }
        }

        ll x = solve(left_array) % MOD;
        ll y = solve(right_array) % MOD;

        // n-1 C leftarray.size()

        ll z = PT[n-1][left_array.size()];

        return (((x*y) % MOD *z)) % MOD;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        PT.resize(n+1);

        //POPULATING PASCAL TRIANGLE
        for(int i = 0; i <= n ; i++){
            PT[i] =vector<ll>(i+1, 1);

            for(int j = 1; j < i ; j++){
                PT[i][j] = (PT[i-1][j-1] + PT[i-1][j]) % MOD;
            }
        }

        return solve(nums) - 1; //ek og bhi rearrangement hoga
    }
};

class Solution {
public:
    int numOfWays(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        int n = nums.size();
        vector<int> born(n + 2, -1);  // insertion time of each value; the walls 0 and n + 1 come before everything
        for (int i = 0; i < n; ++i) born[nums[i]] = i;

        long long fact = 1, sizes = 1;  // n! and the product of subtree sizes, mod p
        for (int k = 2; k <= n; ++k) fact = fact * k % MOD;
        vector<int> stack = {0};  // values with increasing insertion times
        for (int v = 1; v <= n + 1; ++v) {
            while (born[stack.back()] > born[v]) {  // v is the right wall of the value on top
                stack.pop_back();
                sizes = sizes * (v - stack.back() - 1) % MOD;  // and the value below it is the left wall
            }
            stack.push_back(v);
        }
        return (fact * power(sizes, MOD - 2, MOD) - 1 + MOD) % MOD;  // n! / sizes - 1
    }

private:
    long long power(long long b, long long e, long long m) {
        long long r = 1;
        for (b %= m; e; e >>= 1, b = b * b % m)
            if (e & 1) r = r * b % m;
        return r;
    }
};