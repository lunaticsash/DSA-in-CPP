#include<iostream>
using namespace std;

int factorial(int x){
int fact = 1; //initialise
for(int i = 1; i <= x; i++){ // kaha tk
    fact *= i;
    }
    return fact; //ans ko return
}

int ncr(int n, int r){
    int num = factorial(n);//factorial ko call kiya
    int deno=  factorial(r)* factorial (n-r);

    int ans = num/ deno;

    return ans; 

}

int main(){

    int n,r;
    cin>>n>>r;

    int ans = ncr(n,r);
    
    cout<<ans<<endl;


    return 0;

}