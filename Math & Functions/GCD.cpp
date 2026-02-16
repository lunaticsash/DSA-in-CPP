#include<iostream>
using namespace std;

int GCD(int a , int b){//HCF//Given by Euclid
    if(a==0){
        return b;
    }
    if(b==0){
        return a;
    }

    while(a != b){
        if(a>b){
            a = a - b;
        }
        else{
            b = b - a;
        }
    }
    return a;

}

int main(){
    int a,b;
    cout<<"Enter the value of a and b "<<endl;
    cin>>a>>b;

    int ans = GCD(a,b);

    cout<<"GCD of a and b is "<<ans<<endl;
}