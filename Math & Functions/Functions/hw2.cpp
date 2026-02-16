#include<iostream>
using namespace std;

int bits(int n){

    int ans = 0;
    while (n!=0)
    {
        if (n&1){
            ans +=1;
        }
            n = n>>1; //This line updates the value of n
        
    }
    return ans;
    
}

int main(){

    int a,b;
    cin>>a>>b;  
    int first = bits(a);
    int second = bits(b);
    cout<< " total number of set bits are "<< (first + second)<<endl;
}