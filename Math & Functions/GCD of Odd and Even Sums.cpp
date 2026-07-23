#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        return n;
    }
};


/*
    steps:

        sum of first n terms of an AP is : n*(first term + last term)/2
        first n odd numbers are: 1,3,5, ... , 2n-1
        sumOdd = n * (1 + 2n-1) / 2 = n^2
        first n even numbers are: 2,4,6,..,2n
        sumEven = n* (2+2n)/2 = n(n+1)
        we need gcd(sumOdd, sumEven) = gcd(n^2 , n(n+1))
        which is n*gcd(n,n+1)
        as two consecutive numbers are always co-prime, so gcd(n,n+1) = 1
        so gcd(n^2 , n(n+1)) = n
        return n
*/