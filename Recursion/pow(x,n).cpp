#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double ans =1.0;
        long long y = n;

        if(y < 0) y = -1 * y;

        while(y){
            if(y %2){ 
                ans = ans *x;
                y = y - 1;
            }
            else{
                x = x* x;
                y = y/2;
            }
        }
        if(n <0) ans = (double)(1.0)/ (double) (ans);
        return ans;
    }
};

class Solution {
public:
    double myPow(double x, int n) {

    if(n==0) return 1;
        long long N = n;          

        if(N < 0) {
            x = 1 / x;
            N = -N;               
        }
     if(N < 0) return 1 / myPow(x, -N); 

    double halfpow=myPow(x,N/2);
    double halfpowsq=halfpow*halfpow;

        if(N%2!=0){
            return x * halfpowsq;
        }else{
            return halfpowsq;
        }
        
    }
};