#include <bits/stdc++.h> 
int countDistinctWays(int nStairs) {
    //Base case
    if(nStairs<0) return 0;
    if(nStairs==0) return 1;

    //r.r
    return countDistinctWays(nStairs-1)+countDistinctWays(nStairs-2);
}