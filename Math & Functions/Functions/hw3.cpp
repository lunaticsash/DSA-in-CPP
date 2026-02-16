#include<iostream>
using namespace std;

void fibb(int n){
    int a=0 , b = 1;
    cout<< " 0 1" <<" ";
    for(int i = 1 ; i <= n; i++)
    {
        int nextNumber =  a + b;
        cout << nextNumber << " ";
        a = b;
        b = nextNumber;

    }

}
int main(){
    int n;
    cin>>n;
    fibb(n);


}