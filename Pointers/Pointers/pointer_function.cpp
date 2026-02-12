#include<iostream>
using namespace std;

void print(int *p){
    cout<<p<<endl;//Address
    cout<<*p<<endl;//5
}

void update(int *p){
    // p = p + 1;//pass by value ho raha to real mai change nhi hoga
    // cout<<"inside "<<p<<endl;//ab aage bdhega 
    *p= *p+1;//pass by reference ho raha isiliye value change
}

int getSum(int *arr, int n){//int arr[] = *arr hi cz act ye pointer ke tarah hi kr raha pr ye hai hi pointer 

    cout<<endl<<"Size is : "<<sizeof(arr)<<endl;

    int sum = 0;

    for(int i = 0; i<n; i++){
        sum+=i[arr];
    }
    return sum;
}

int main(){

    // int value= 5;
    // int *p = &value;

    // print(p);

    // cout<<"Before "<<*p<<endl;
    // update(p);
    // cout<<"After "<<*p<<endl;

    int arr[6]={1,2,3,4,5,8};

    cout<<"Sum is "<<getSum(arr+3,3)<<endl;


    return 0;
}